#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "Vector2.h"
#include "PhysicsElement.h"
#include "Sprite.h"

class Ball: public PhysicsElement, public Sprite
{
public:
	// all balls have a size
	Ball(std::string location, Vector2 pos, Vector2 size, Vector2 velocity, double mass);
	PhysicsElement* Ball::collisionDetection(PhysicsElement* e);
private:
	Vector2 p;
};

#endif