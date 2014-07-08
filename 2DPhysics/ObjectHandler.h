#include<iostream> 
#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H
#include"Drawable.h"
#include"PhysicsElement.h"
#include"Object.h"
#include<vector>
using namespace std;

class ObjectHandler
{	
	// FIXME: Can we have a single Object vector and then look for eacht object if it is drawable?
	vector<Drawable*> d_vec;
	vector<PhysicsElement*> p_vec;
public:
	void draw_objects();
	void add_object(Object* obj);
	//void add_object(PhysicsElement* obj);
	void update_physics(double t);
	void destroy_objects();
};
#endif