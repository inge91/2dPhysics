
#include "Bitmap.h"


Bitmap::Bitmap(std::string location, Vector2 size)
{
	createBitmap(location, size);
}

void Bitmap::createBitmap(std::string location, Vector2 size)
{
	bm = imread(location, CV_LOAD_IMAGE_GRAYSCALE);
	
	resize(bm, bm, Size(Drawable::meters2Pixels(size.x), Drawable::meters2Pixels(size.y)));
	threshold(bm, bm, 220, 255, THRESH_BINARY);
}