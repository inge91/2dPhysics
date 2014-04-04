#include "PhysicsElement.h"

PhysicsElement::PhysicsElement(std::string location, Vector2 size, Vector2 *pos, Vector2 velocity, Vector2 acc, double mass)
	: Sprite(location, pos, size)
{
	p = pos;
	prevp = NULL;
	v = velocity;
	a = acc;
	m = mass;
}

Vector2 PhysicsElement::calculateForces(Sprite *e )
{
	Vector2 t(0, 0);

	return t;
}

bool first = true;
void PhysicsElement::updatePhysics(double t, Sprite *e)
{		
	
		Vector2 forces = calculateForces(e);

		// Update position given active forces
		a += forces * (1/m);
		// Update velocity
		v += a * t;

		// gravity (this should be added to the calculate forces)
		Vector2 gravity(0, 9.81);

		v += gravity * t;


		if(e != NULL)
		{
			if(first == true)
			{
			cout<<"Before bounce"<<endl;
				cout<<v<<endl;
			}
		

			v = Vector2(v.x, -v.y * 0.96 );
			if(first == true)
			{
			cout<<"After bounce"<<endl;
				cout<<v<<endl;
			}
		
			first = false;
		}
		else
		{
			first = true;
		}

	
		// store previous position
		prevp->x = p->x;
		prevp->y = p->y;

		// Update position
		*p += v * t;



		// Add drag
		//v *= pow(d, t);
}

 Sprite* PhysicsElement::collisionDetection(Sprite* e)
{
	
	if(e != NULL)
	{
		vector<Vector2> v = bm.detectCollision(e->bm);
		if((v)[0].x != 0)
		{
			collisions.push_back((v)[0]);
			collisions.push_back((v)[1]);
			if(v.size() == 3)
			{
				return e;
			}
		}
	}
	

	return NULL;
	
}

Vector2 PhysicsElement::getVelocity()
{
	return v;
}

Vector2 PhysicsElement::getPosition()
{
	return *p;
}
