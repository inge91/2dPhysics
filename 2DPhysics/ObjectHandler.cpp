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
	PhysicsElement *e;
	
	for(std::vector<int>::size_type i = 0; i != p_vec.size(); i++) 
	{
		e = NULL;
		for(std::vector<int>::size_type j = i+1; j != p_vec.size(); j++)
		{
			e = p_vec[i]->collisionDetection(p_vec[j]);
			
			// In case we collide with another object break (So only one collision is taken into account right now) FIXME
			if(e != NULL)
			{
				break;
			}
		}
		// This case should be removed after all things are up and running
		if(p_vec.size() == 1)
		{
			e = p_vec[0]->collisionDetection(p_vec[0]);
		}
		p_vec[i]->updatePhysics(t, e);
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

