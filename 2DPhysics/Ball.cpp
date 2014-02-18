#include "Ball.h"

Ball::Ball(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass)
	:  p(pos.x, pos.y), PhysicsElement(location, size, &p, velocity, Vector2(0,0), mass)
{
}



PhysicsElement* Ball::collisionDetection(PhysicsElement* e)
{
	return NULL;
}