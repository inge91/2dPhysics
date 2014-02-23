#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Object.h"
class Drawable: public virtual Object
{
	public:

	// Draws the element to screen
	virtual void draw() = 0;

	// One meter is 50 pixels
	static const int m = 50;

	//FIXME: This used to be protected
	//Meters to pixels
	static double meters2Pixels(double p);
	static double pixels2Meters(double p);
};

#endif