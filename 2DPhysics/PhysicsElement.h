#ifndef PHYSICSELEMENT_H
#define PHYSICSELEMENT_H
#include "Vector2.h"
#include <iostream> 

class PhysicsElement
{
	// Position
	protected:	
	Vector2 p;
	Vector2 v;
	Vector2 a;
	double m;

	public:
	// We excpect all physical elements to have a position, velocity, acceleration and mass
	PhysicsElement(Vector2 pos, Vector2 velocity, Vector2 acc, double mass);
	Vector2 getVelocity();
	Vector2 getPosition();
	void updatePhysics(double t);
	Vector2 calculateForces();
};

#endif