#include "ObjectHandler.h"

void ObjectHandler::draw_objects()
{
	// Draw particles and their position
	for(Drawable *d: d_vec)
	{
		d->draw();	
	}
}
void ObjectHandler::update_physics(double t)
{
	for(PhysicsElement *p: p_vec)
	{
		p->updatePhysics(t);
	}
}


// Adds objects to all the different lists
void ObjectHandler::add_object(Object* obj)
{
	if(dynamic_cast<Drawable*>(obj) != NULL)
	{
		d_vec.push_back(dynamic_cast<Drawable*>(obj));		
	}
	if(dynamic_cast<PhysicsElement*>(obj) != NULL)
	{
		p_vec.push_back(dynamic_cast<PhysicsElement*>(obj));		
	}
}
