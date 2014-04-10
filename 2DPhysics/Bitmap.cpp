
#include "Bitmap.h"


Bitmap::Bitmap(std::string location, Vector2 size)
	:s(size.x, size.y)
{
	createBitmap(location, size);
}

void Bitmap::setPosition(Vector2* pos)
{
    p = pos;
}

void Bitmap::createBitmap(std::string location, Vector2 size)
{
	// TODO: read alpha values
	bm = imread(location, CV_LOAD_IMAGE_GRAYSCALE);
    
	resize(bm, bm, Size(Drawable::meters2Pixels(size.x), Drawable::meters2Pixels(size.y)));

	threshold(bm, bm, 220, 255, THRESH_BINARY);
	cv::bitwise_not(bm, bm);
}

// Checks if there is collision between bitmaps (overlapping pixels that are occupied)
vector<Vector2> Bitmap::detectCollision(Bitmap bm2, Vector2 p1, Vector2 p2)
{

	// Find the region of collision detection
	vector<Vector2> r = detectOverlap(*this, bm2, p1, p2);
	// Create 2 matrices with the format described in s.
	double px1 = Drawable::meters2Pixels(p1.x);
	double py1 = Drawable::meters2Pixels(p1.y);
	double vecx1 = Drawable::meters2Pixels(s.x);
	double vecy1 = Drawable::meters2Pixels(s.y);

	double px2 = Drawable::meters2Pixels(p2.x);
	double py2 = Drawable::meters2Pixels(p2.y);
	double vecx2 = Drawable::meters2Pixels(bm2.s.x);
	double vecy2 = Drawable::meters2Pixels(bm2.s.y);
	
	int width =  abs(r[1].x - r[0].x);
	int height = abs(r[1].y - r[0].y);
	if(width > 0 && height > 0)
	{
		int xoffset1 = abs(r[0].x - (px1 - vecx1/2));
		int xoffset2 = abs(r[0].x - (px2 - vecx2/2));
		int yoffset1 = abs(r[0].y - (py1 - vecy1/2));
		int yoffset2 = abs(r[0].y - (py2 - vecy2/2));

		cv::Mat m1 = bm(cv::Rect(xoffset1, yoffset1, width, height));

		cv::Mat m2 = bm2.bm(cv::Rect(xoffset2, yoffset2, width, height));
		Mat m3;
		cv::bitwise_and(m1, m2, m3);

		if(countNonZero(m3) > 1)
		{
			Vector2 v;
			v.x = 1;
			v.y = 1;
			r.push_back(v);
		}
	}

	return r;
}


// Determines if there is overlap between the bitmaps 
// Check for left upper corner overlap like so:
/*
------------
|		   |
|		   |
|          |
|       *---------
|		|		 |
--------|        |
		|		 |
		----------
*/	
// LU can also fall outside of the bitmap underneath

/*
 *Returns the overlap bounding box in pixels position
 */
vector<Vector2> Bitmap::detectOverlap(Bitmap bm, Bitmap bm2, Vector2 pf, Vector2 ps,  int reversed)
{
	Vector2 p1;
	Vector2 p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;

	float yd1 = Drawable::meters2Pixels(pf.y) 
        - Drawable::meters2Pixels(bm.s.y/2);
	float yu1 = Drawable::meters2Pixels(pf.y) 
        + Drawable::meters2Pixels(bm.s.y/2);
	float yd2 = Drawable::meters2Pixels(ps.y) 
        - Drawable::meters2Pixels(bm2.s.y/2);
	float yu2 = Drawable::meters2Pixels(ps.y) 
        + Drawable::meters2Pixels(bm2.s.y/2);
	float xl1 = Drawable::meters2Pixels(pf.x) 
        - Drawable::meters2Pixels(bm.s.x/2);
	float xr1 = Drawable::meters2Pixels(pf.x) 
        + Drawable::meters2Pixels(bm.s.x/2);
	float xl2 = Drawable::meters2Pixels(ps.x) 
        - Drawable::meters2Pixels(bm2.s.x/2);
	float xr2 = Drawable::meters2Pixels(ps.x) 
        + Drawable::meters2Pixels(bm2.s.x/2);

	// highest point of square1 falls between second square
	if(yd1 > yd2 && yd1 < yu2)
	{
        
		// left most point of square 1 falls between second square
		if(xl1 > xl2 && xl1 < xr2 )
		{
			p1.x = xl1;
			p1.y = yd1;

			if(xr1 < xr2)
			{
				p2.x = xr1;
			}
			else p2.x = xr2;
			if(yu1 < yu2)
			{
				p2.y = yu1;
			}
			else p2.y = yu2;
		}
		// underside of square 2 falls in square 1
		if(xl1 <= xl2 && xr1 >= xl2)
		{
			p1.x = xl2;
			p1.y = yd1;

			// Check right corner point
			if(xr1 < xr2)
			{
				p2.x = xr1;
			}
			else p2.x = xr2;

			if(yu1 < yu2)
			{
				p2.y = yu1;
			}
			else p2.y =yu2;
		}
	}
	// If nothing is set and bm are not yet reversed, 
	// call function again with reversed bitmaps
	if (p1.x == NULL && !reversed)
	{
		return detectOverlap(bm2, bm, ps, pf, 1);
	}
	// Else return the points in a vector 
	else{
		vector<Vector2> r;
		r.push_back(p1);
		r.push_back(p2);

		return r;
	}
}
