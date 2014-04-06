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
	Sprite *e;

	// This case should be removed after all things are up and running
	if(p_vec.size() == 1)
	{
		// Check with all static boundaries
		
		for(std::vector<int>::size_type i = 0; i != s_vec.size(); i++)
		{
			e = p_vec[0]->collisionDetection(s_vec[i]);
		}

		p_vec[0]->updatePhysics(t, e);
	}
	/////////////////////////////////////////////////////////////////
	else{

		for(std::vector<int>::size_type i = 0; i != p_vec.size(); i++) 
		{
			e = NULL;
            for(std::vector<int>::size_type j = 0; j != s_vec.size(); j++)
            {
                
                e = p_vec[i]->collisionDetection(s_vec[j]);

            }

            for(std::vector<int>::size_type k = 0; k != p_vec.size(); k++)
            {
                
                e = p_vec[i]->collisionDetection(p_vec[k]);

            }
            
		
			p_vec[i]->updatePhysics(t, e);
		}
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

	if(dynamic_cast<StaticElement*>(obj) != NULL)
	{
		s_vec.push_back(dynamic_cast<StaticElement*>(obj));		
	}
}


void ObjectHandler::destroy_objects()
{
	d_vec.clear();
	p_vec.clear();
}
