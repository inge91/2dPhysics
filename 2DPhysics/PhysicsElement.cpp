#include "PhysicsElement.h"
// TODO//:
//      fix the minimum velocity an object can have(to stop endless bouncing)
//      Dynamic dynamic collision
//      friction constant? 
//      Add plasticity factor between the specific elements (the bounce constant)
//      

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 pos, Vector2 velocity, Vector2 acc, double plasticity, double mass)
	: Sprite(location, pos, size)
{
	v = velocity;
	a = acc;
	m = mass;

    pl = plasticity;
}

Vector2 PhysicsElement::calculateForces(Sprite *e )
{
	Vector2 t(0, 0);

	return t;
}



void PhysicsElement::calculateVelocity(Sprite *e, double t)
{

		if(dynamic_cast<StaticElement*>(e) != NULL)
		{
            // Only if velocity is strong enough make the bounce
            v = Vector2(v.x, -v.y * pl );
        }

        else if(dynamic_cast<PhysicsElement*>(e) != NULL)
	    {
			//v = Vector2(-v.x*100, -v.y  );
            Vector2 v2 = dynamic_cast<PhysicsElement*>(e)->getVelocity();
            double m2 = dynamic_cast<PhysicsElement*>(e)->getMass();
            v.x = (abs(v.x) * (m -  m2) + (2 * m2 * abs(v2.x))) /
               (m + m2) ;
            v.y= (abs(v.y) * (m -  m2) + (2 * m2 * abs(v2.y))) /
               (m + m2) ;
            v2.x = (abs(v2.x) * (m2 -  m) + (2 * m * abs(v.x))) /
               (m + m2) ;
            v2.y= -(abs(v2.y) * (m2 -  m) + (2 * m * abs(v.y))) /
               (m + m2) ;
        cout<<"Object with weigth "<<  m<<endl;
            cout<<v<<endl;
        cout<<"Object with weigth "<<  m2<<endl;
            cout<<v2<<endl;
        }
        else
        {
            cout<<"Go down"<<endl;
        }


}

void PhysicsElement::updatePosition(double t)
{
		// Update velocity
		v += a * t;
		// gravity (this should be added to the calculate forces)
	    Vector2 gravity(0, 9.81);
		    v += gravity * t;
        // Let's add some wind
        Vector2 wind (5, 0);


        cout<<"Object with weigth "<<  m<<endl;
        cout<<v<<endl;
        
        //v += wind *t;
		// store previous position
        prevp = p;

        // If the velocity is too small, set to 0.
		// Update position
		p += v * t;
}

/*
void PhysicsElement::updatePhysics(double t, Sprite *e)
{		

		// Add drag
		//v *= pow(d, t);
}*/

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

            if((v)[0].x != 0)
            {
                return e;
            }
        }

		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
				return e;
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
        v =  tmp.bm.detectCollision(e.bm, tmp.p, e.p);

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

double PhysicsElement::getMass()
{
    return m;
}

Vector2 PhysicsElement::getPosition()
{
	return p;
}
