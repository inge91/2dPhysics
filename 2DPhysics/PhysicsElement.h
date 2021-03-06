#ifndef PHYSICSELEMENT_H
#define PHYSICSELEMENT_H
#include "Vector2.h"
#include <iostream> 
#include "Object.h"
#include "Sprite.h"

class PhysicsElement : public Sprite
{
	// Position
	protected:	
	Vector2 *p;
	Vector2 *prevp;
	Vector2 v;
	Vector2 a;
	double m;

	public:
	// We excpect all physical elements to have a position, velocity, acceleration and mass
	PhysicsElement(std::string location, Vector2 size, Vector2 *pos, Vector2 velocity, Vector2 acc, double mass);
	Vector2 getVelocity();
	Vector2 getPosition();
	void updatePhysics(double t, PhysicsElement *e);
	Vector2 calculateForces(PhysicsElement *e);
	// Input argument should probably be something that also work on "static" objects
	PhysicsElement* collisionDetection(PhysicsElement* e);
};

#endif