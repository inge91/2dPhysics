#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"Vector2.h"
#include"PhysicsElement.h"

class Rectangle: public PhysicsElement
{

public:
		Rectangle(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass);
};

#endif
