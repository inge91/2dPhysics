#include "Rectangle.h"

Rect::Rect(Vector2 size, Vector2 *pos, Vector2 velocity, double mass)
	: PhysicsElement(pos, velocity, Vector2(0,0), mass), size(size.x, size.y)
{

}

void Rect::draw()
{
	glRectf(Drawable::meters2Pixels(p->x) - (size.x/2.0),
		Drawable::meters2Pixels(p->y) - (size.y/2.0), 
		Drawable::meters2Pixels(p->x) + (size.x/2.0), 
		Drawable::meters2Pixels(p->y) + (size.y/2.0));
}

PhysicsElement* Rect::collisionDetection(PhysicsElement* e)
{
	if(p->y + (size.y/2) > 480)
	{
		return e;
	}
	return NULL;
}