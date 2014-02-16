#include "Particle.h"
using namespace std;
// Wooo everything is handled by virtual class!
/*
Particle::Particle()
	: PhysicsElement(Vector2(0,0), Vector2(0,0), Vector2(0,0), 0)
{
}

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

void Particle::draw()
{
		glBegin(GL_POINTS);
		glVertex2f( Drawable::meters2Pixels(p->x) , Drawable::meters2Pixels(p->y));
		glEnd();
}

bool Particle::collisionDetection()
{
	if(p->y > 480)
	{
		return true;
	}
}*/