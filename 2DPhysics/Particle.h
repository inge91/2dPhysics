#ifndef PARTICLE_H
#define PARTICLE_H
#include "PhysicsElement.h"
#include "Vector2.h"
#include "Drawable.h"
#include "GL\freeglut.h"
#include "GL\glut.h"
#include <iostream> 
class Particle: public PhysicsElement, public Drawable
{
	public:
		Particle();
		Particle(Vector2 pos, double mass);
		Particle(Vector2 pos, Vector2 velocity, double mass);
		Particle(Vector2 pos, Vector2 velocity, Vector2 acceleration, double mass);
		void update(double t);
		void draw();
};

#endif;