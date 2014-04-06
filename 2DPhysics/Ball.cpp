#include "Ball.h"

Ball::Ball(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass)
	: PhysicsElement(location, size, pos, velocity, Vector2(0,0), mass)
{
}


