#include "PhysicsElement.h"
// TODO//:
//      At each collision step check if already is collided
//                  (Do this for static and dynamic objects)
//      fix the minimum velocity an object can have(to stop endless bouncing)

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 *pos, Vector2 velocity, Vector2 acc, double mass)
	: Sprite(location, pos, size)
{
	p = pos;
    
    double px = pos->x;
    double py = pos->y;
    Vector2 v(pos->x,pos->y);
    prevp = &v;
    
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
			if(first == true)
			{
//			cout<<"Before bounce"<<endl;
//				cout<<v<<endl;
			}
		

			v = Vector2(v.x, -v.y * 0.2 );
			if(first == true)
			{
//			cout<<"After bounce"<<endl;
//				cout<<v<<endl;
			}
		
			first = false;
		}
		else
		{
			first = true;
		}

	
		// store previous position
         x = p->x;
         y = p->y;
         prevp->x = 3;
         prevp->y = 6;

        cout<<"UPDATE PHYSICS STEP"<<endl;
        cout<<"prevp"<<endl;
        cout<<prevp->x<<endl;
        cout<<"prevp"<<endl;
        cout<<prevp->x<<endl;
		// Update position
		//*p += v * t;
        cout<<"prevp"<<endl;
         cout<<*prevp<<endl;
        cout<<"p"<<endl;
         cout<<*p<<endl;
         cout<<"stop"<<endl;
         exit(0);

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
        cout<<"HERREE"<<endl;
        cout<<*prevp<<endl;
        cout<<*p<<endl;
        cout<<"END"<<endl;
	    if(dynamic_cast<StaticElement*>(e) != NULL)
	    {
           //v = collisionDetectionStatic(e->bm);
		   v = bm.detectCollision(e->bm);
        }
        // The two dynamic objects case
        else
        {
		    v = bm.detectCollision(e->bm);
        }

		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
			if(v.size() == 3)
			{
				return e;
			}
		}
	}
	
	return NULL;
	
}

// checks for collision with static object by walking through every pixel
// between the previous and new position
vector<Vector2> PhysicsElement::collisionDetectionStatic(Bitmap bm2)
{

    cout<<"prevp"<<endl;
    cout<<*prevp<<endl;
    cout<<"p"<<endl;
    cout<<*p<<endl;

    // Find pixel value of prev and current positio
    int prevx = (int)Drawable::meters2Pixels(prevp->x);
    int prevy = (int)Drawable::meters2Pixels(prevp->y);
    cout<<"Begin pixels" <<endl;
    cout<< prevx << " , "<<prevy<<endl;
    int px = (int)Drawable::meters2Pixels(p->x);
    int py = (int)Drawable::meters2Pixels(p->y);
    cout<<"End pixels" <<endl;
    cout<< px << " , "<<py<<endl;
    
    // Loop through all pixels on the line from start to end positions
    // and check for intersections. In case intersection break.
    Bitmap tmp = this->bm;


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
            tmp.p->x = y;
            tmp.p->y = x;

        }
        else
        {
            tmp.p->x = x;
            tmp.p->y = y;
        }
        
        // Calculate collision
        v =  tmp.detectCollision(bm2);
        cout<<"Between position: "<<endl;
        cout<<*tmp.p<<endl;
        
        // In case of collision return it
        if((v)[0].x !=0)
        {
            cout<<"we have a early collision"<<endl;
            // Set position of object to new bm val
            this->p->x = Drawable::pixels2Meters(tmp.p->x);
            this->p->y = Drawable::pixels2Meters(tmp.p->y);
            return v;
            
        }

        error -= deltay;
        if(error < 0)
        {
            y += ystep;
            error += deltax;
        }
    }
    return v;

}



Vector2 PhysicsElement::getVelocity()
{
	return v;
}

Vector2 PhysicsElement::getPosition()
{
	return *p;
}
