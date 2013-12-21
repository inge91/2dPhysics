#include "PhysicsElement.h"

PhysicsElement::PhysicsElement(Vector2 pos, Vector2 velocity, Vector2 acc, double mass)
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
		p += v * t;
	
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

Vector2 PhysicsElement::getVelocity()
{
	return v;
}

Vector2 PhysicsElement::getPosition()
{
	return p;
}
