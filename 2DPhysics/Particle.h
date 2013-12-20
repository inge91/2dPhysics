#ifndef PARTICLE_H
#define PARTICLE_H
#include "PhysicsElement.h"
#include "Vector2.h"
#include <iostream> 
class Particle: virtual PhysicsElement
{
	public:
		Particle();
		Particle(Vector2 pos, double mass);
		Particle(Vector2 pos, Vector2 velocity, double mass);
		Particle(Vector2 pos, Vector2 velocity, Vector2 acceleration, double mass);
		Vector2 getVelocity();
		Vector2 getPosition();
		void update(double t);
};

#endif;