#include "Drawable.h"
#include "PhysicsElement.h"
#include "GL\freeglut.h"
#include "GL\glut.h"
#define _USE_MATH_DEFINES
#include <math.h>


class Circle: public Drawable, public PhysicsElement
{
	// Radius  of circle
	double r;
	public: 
		Circle::Circle(double radius, Vector2 pos, Vector2 velocity, double mass);

	void draw();

};