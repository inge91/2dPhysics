#ifndef PHYSICSELEMENT_H
#define PHYSICSELEMENT_H
#include "Vector2.h"
#include <iostream> 
#include "Object.h"
#include "StaticElement.h"
#include "Sprite.h"
#include"opencv/cv.h"
#include"opencv2/opencv.hpp"
#ifdef __linux__
#include <unistd.h>
#endif

class PhysicsElement : public Sprite
{
	// Position
	protected:	
	Vector2 v;
	Vector2 a;
	double m;
    double pl;

	public:
	// We excpect all physical elements to have a position, velocity, acceleration and mass
	PhysicsElement(std::string location, Vector2 size, Vector2 pos, Vector2 velocity, Vector2 acc, double plasticity, double mass);
	Vector2 getVelocity();
	Vector2 getPosition();
	void updatePhysics(double t, Sprite *e);
    void calculateVelocity(Sprite *e, double t);
    void updatePosition(double t);
	Vector2 calculateForces(Sprite *e);
	// Input argument should probably be something that also work on "static" objects
	Sprite* collisionDetection(Sprite* e);
    vector<Vector2> collisionDetectionStatic(Sprite e);
};

#endif
