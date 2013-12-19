#ifndef PHYSICSELEMENT_H
#define PHYSICSELEMENT_H
#include "Vector2.h"
#include <iostream> 

class PhysicsElement
{
	// Position

	// TODO: maybe change position to a recanglte?
	protected:	
	Vector2 p;
	Vector2 v;
	Vector2 a;
	double m;

	public:
	// We excpect all physical elements to have a position, velocity, acceleration and mass
	PhysicsElement(Vector2 pos, Vector2 velocity, Vector2 acc, double mass);
	virtual Vector2 getVelocity() = 0;
	void updatePhysics(double t);
	Vector2 calculateForces();
};

#endif