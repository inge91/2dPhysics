#ifndef BOX_H
#define BOX_H
#include "Rectangle.h"
#include <iostream> 
class Box: public Rectangle
{
	public:
		Box(Vector2 pos, Vector2 velocity);
};




#endif // !BOWLINGBALL_H
