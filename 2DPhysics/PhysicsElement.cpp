#include "PhysicsElement.h"

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 *pos, Vector2 velocity, Vector2 acc, double mass)
	: Sprite(location, pos, size)
{
	p = pos;
	v = velocity;
	a = acc;
	m = mass;
}

Vector2 PhysicsElement::calculateForces()
{
	// Right now we only have the force of gravity...
	Vector2 t(0, 0);
	return t;
}

void PhysicsElement::updatePhysics(double t, PhysicsElement *e)
{		
		// Update position
		*p += v * t;

		Vector2 forces = calculateForces();
		// Update position given active forces
		a += forces * (1/m);

		// Update velocity
		v += a * t;
		
		// gravity
		Vector2 gravity(0, 9.81);
		
		v += gravity * t;
 		
		if(e != NULL)
		{
			v = Vector2(0, 0);
		}
		// Add drag
		//v *= pow(d, t);
}

 PhysicsElement* PhysicsElement::collisionDetection(PhysicsElement* e)
{
	
	if(Drawable::meters2Pixels(p->y + size.y) > 480)
	{
		return this;
	}
	if(e != NULL)
	{
		vector<Vector2> v = bm.detectCollision(e->bm);
		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
			if(v.size() == 3)
			{
				return this;
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
