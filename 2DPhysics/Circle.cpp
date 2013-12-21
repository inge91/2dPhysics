#include "Circle.h"
Circle::Circle(double radius, Vector2 pos, Vector2 velocity, double mass)
	: PhysicsElement(pos, velocity, Vector2(0,0), mass)
{
	r = radius;
}

// Draws a nice little circle
void Circle::draw()
{
	double px = Drawable::meters2Pixels(p.x);
	double py = Drawable::meters2Pixels(p.y);
	double vecx = -Drawable::meters2Pixels(r);
	double vecy = 0;
	double newx = 0;
	double newy = 0;

	glBegin(GL_TRIANGLE_FAN);	
	glVertex2f(px, py);

	glVertex2f(px + vecx, py + vecy);
	int angle = 10;
		
	for(int i = angle; i <= 360; i += angle)
	{
		newx = cos(angle *  (M_PI/180)) * vecx + -sin(angle * (M_PI/180)) * vecy;
		newy = sin(angle * (M_PI/180)) * vecx + cos(angle * (M_PI/180)) * vecy;
		vecx = newx;
		vecy = newy;
		glVertex2f(px + vecx, py + vecy);
	}
	glEnd();

}

// FIXME This should return the object with which is collided
bool Circle::collisionDetection()
{
	if(Drawable::meters2Pixels(p.y + r) > 480)
	{
		return true;
	}
	return false;
}