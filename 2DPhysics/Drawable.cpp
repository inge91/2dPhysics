#include "Drawable.h"

double Drawable::meters2Pixels(double p)
{
	return p * m;
}

double Drawable::pixels2Meters(double p)
{
	return p/m;
}