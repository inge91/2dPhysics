#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Drawable.h"
#include "PhysicsElement.h"
#include "GL\freeglut.h"
#include "GL\glut.h"
// This should be an interface? 
class Rect: public Drawable, public PhysicsElement
{
	// Rectangle size
	/*Rectangle();
	double h;
	double l;
	*/
	// Rectangle size (height and width)
	Vector2 size;
	public:
		Rect(Vector2 size, Vector2 pos, Vector2 velocity, double mass);
		void draw();
};

#endif