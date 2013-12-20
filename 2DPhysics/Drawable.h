#ifndef DRAWABLE_H
#define DRAWABLE_H
class Drawable
{
	public:

	// Draws the element to screen
	virtual void draw() = 0;

	// One meter is 50 pixels
	static const int m = 50;

	protected:
		//Meters to pixels
		static double meters2Pixels(double p);
};

#endif