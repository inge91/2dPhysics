#include "Particle.h"

// Wooo everything is handled by virtual class!
Particle::Particle(Vector2 pos, double mass)
	: PhysicsElement(pos, Vector2(0, 0), Vector2(0,0), mass)
{

}
Particle::Particle(Vector2 pos, Vector2 velocity, double mass)
	: PhysicsElement(pos, velocity, Vector2(0,0), mass)
{

}

Particle::Particle(Vector2 pos, Vector2 velocity, Vector2 acceleration, double mass)
	: PhysicsElement(pos, velocity, acceleration, mass)
{

}

Vector2 Particle::getVelocity()
{
	return v;
}

Vector2 Particle::getPosition()
{
	return p;
}