#ifndef BOWLINGBALL_H
#define BOWLINGBALL_H

#include "Ball.h"
#include <iostream> 
class BowlingBall: public Ball
{
	public:
		BowlingBall(Vector2 pos, Vector2 velocity);
};




#endif // !BOWLINGBALL_H
