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
	Vector2 t(0, 9.81);
	return t;
}

void PhysicsElement::updatePhysics(double t)
{
		
		// Update position
		p += v * t;

		Vector2 forces = calculateForces();
		// Update position given active forces
		a += forces * (1/m);

		
		// Update velocity
		v += a * t;


		// Add drag
		//v *= pow(d, t);
}

