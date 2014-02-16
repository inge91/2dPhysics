#include "Ball.h"

// BOOM, multiple inheritance
Ball::Ball(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass)
	:  p(pos.x, pos.y), PhysicsElement(&p, velocity, Vector2(0,0), mass), Sprite(location, &p, size)
{
}



PhysicsElement* Ball::collisionDetection(PhysicsElement* e)
{
	return NULL;
}