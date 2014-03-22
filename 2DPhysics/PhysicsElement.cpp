#include "PhysicsElement.h"

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 *pos, Vector2 velocity, Vector2 acc, double mass)
	: Sprite(location, pos, size)
{
	p = pos;
	v = velocity;
	a = acc;
	m = mass;
}

Vector2 PhysicsElement::calculateForces(Sprite *e )
{
	Vector2 t(0, 0);
	
	// Right now we only have the force of gravity...
	if(e != NULL)
	{
		t.y = -3;
	}
	return t;
}

void PhysicsElement::updatePhysics(double t, Sprite *e)
{		
		// Update position
		*p += v * t;

		Vector2 forces = calculateForces(e);

		// Update position given active forces
		a += forces * (1/m);


		
 		
		if(e != NULL)
		{
			v = Vector2(0, 0);
		}

	// Update velocity
		v += a * t;
		cout<<v<<endl;

		// gravity (this should be added to the calculate forces)
		Vector2 gravity(0, 9.81);

		v += gravity * t;

		// Add drag
		//v *= pow(d, t);
}

 Sprite* PhysicsElement::collisionDetection(Sprite* e)
{
	
/*	if(Drawable::meters2Pixels(p->y + size.y) > 480)
	{
		return this;
	}*/
	if(e != NULL)
	{
		vector<Vector2> v = bm.detectCollision(e->bm);
		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
			if(v.size() == 3)
			{
				cout<<"got a hit"<<endl;
				return e;
			}
		}
	}
	

	return NULL;
	
}

Vector2 PhysicsElement::getVelocity()
{
	return v;
}

Vector2 PhysicsElement::getPosition()
{
	return *p;
}
