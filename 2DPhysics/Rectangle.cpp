#include "Rectangle.h"

Rectangle::Rectangle(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass)
	:  p(pos.x, pos.y), PhysicsElement(location, size, &p, velocity, Vector2(0,0), mass)
{
}


