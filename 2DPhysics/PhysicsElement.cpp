#include "PhysicsElement.h"
// TODO//:
//      At each collision step check if already is collided  DONE
//                  (Do this for static and dynamic objects)
//      fix the minimum velocity an object can have(to stop endless bouncing)

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 pos, Vector2 velocity, Vector2 acc, double mass)
	: Sprite(location, pos, size)
{
	v = velocity;
	a = acc;
	m = mass;
}

Vector2 PhysicsElement::calculateForces(Sprite *e )
{
	Vector2 t(0, 0);

	return t;
}

bool first = true;
double x = 0;
double y = 0;
void PhysicsElement::updatePhysics(double t, Sprite *e)
{		
	
		Vector2 forces = calculateForces(e);

		// Update position given active forces
		a += forces * (1/m);
		// Update velocity
		v += a * t;

		// gravity (this should be added to the calculate forces)
		Vector2 gravity(0, 9.81);

		v += gravity * t;


		if(e != NULL)
		{
			v = Vector2(v.x, -v.y * 0.5 );
		
			first = false;
		}
		else
		{
			first = true;
		}

	
		// store previous position
         prevp = p;

		// Update position
		p += v * t;

		// Add drag
		//v *= pow(d, t);
        
}

 Sprite* PhysicsElement::collisionDetection(Sprite* e)
{
    // Calculate collisiton for this object
	
	if(e != NULL)
	{
        vector<Vector2> v;

        // In case we check for collision with a static object,
        // Check for all between positions if collision has happened
        // already
	    if(dynamic_cast<StaticElement*>(e) != NULL)
	    {
           v = collisionDetectionStatic(*e);
        }
        // The two dynamic objects case
        else
        {
		   v = bm.detectCollision(e->bm, p, e->p);
        }

		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
			if(v.size() == 2)
			{
                cout<<"Hit tomething"<<endl;
				return e;
			}
		}
	}
	
	return NULL;
	
}

// checks for collision with static object by walking through every pixel
// between the previous and new position
vector<Vector2> PhysicsElement::collisionDetectionStatic(Sprite e)
{

    // Find pixel value of prev and current positio
    int prevx = (int)Drawable::meters2Pixels(prevp.x);
    int prevy = (int)Drawable::meters2Pixels(prevp.y);
    int px = (int)Drawable::meters2Pixels(p.x);
    int py = (int)Drawable::meters2Pixels(p.y);

    cout<<"Begin pixels" <<endl;
    cout<< prevx << " , "<<prevy<<endl;
    cout<<"End pixels" <<endl;
    cout<< px << " , "<<py<<endl;
        
    
    // Loop through all pixels on the line from start to end positions
    // and check for intersections. In case intersection break.
    PhysicsElement tmp = *this;


   // This is an implementation of Bresenham's Algorithm (check http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
    int isSteep = std::abs(py - prevy) > abs(px - prevx);
    if(isSteep)
    {
        std::swap(prevx, prevy);
        std::swap(px, py);
    }

    int deltax = px - prevx;
    int deltay = py - prevy;
    int error = deltax / 2;
    int y = prevy;
    int ystep;
    prevy < py ? ystep = 1 : ystep = -1; 

    // Initialize v with a single point that has zero values.
    vector<Vector2> v;
    Vector2 zeroPoint(0, 0);
    v.push_back(zeroPoint);
    for(int x = prevx; x < px; x++)
    {
        if(isSteep)
        {
            tmp.p.x = Drawable::pixels2Meters(y);
            tmp.p.y = Drawable::pixels2Meters(x);

        }
        else
        {
            tmp.p.x = Drawable::pixels2Meters(x);
            tmp.p.y = Drawable::pixels2Meters(y);
        }
        
        // Calculate collision
        cout<<tmp.p<<endl;
        v =  tmp.bm.detectCollision(e.bm, tmp.p, e.p);

        cout<<"Between position: "<<endl;
        cout<<Drawable::meters2Pixels(tmp.p.x)<<endl;
        cout<<Drawable::meters2Pixels(tmp.p.y)<<endl;
        // In case of collision return it
        if((v)[0].x !=0)
        {
            // Set position of object to new bm val
            this->p.x = tmp.p.x;
            this->p.y = tmp.p.y;
            return v;
            
        }

        error -= deltay;
        if(error < 0)
        {
            y += ystep;
            error += deltax;
        }
    }

    v =  bm.detectCollision(e.bm, p, e.p);
    return v;

}



Vector2 PhysicsElement::getVelocity()
{
	return v;
}

Vector2 PhysicsElement::getPosition()
{
	return p;
}
