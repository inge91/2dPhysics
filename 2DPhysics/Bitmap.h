#ifndef BITMAP_H
#define BITMAP_H

#include<iostream>
#include"Vector2.h"
#include"opencv/cv.h"
#include"opencv2/opencv.hpp"
#include"Drawable.h"
using namespace cv;



class Bitmap 
{
	
public:
	Bitmap(std::string location, Vector2 *pos, Vector2 size);
	vector<Vector2> detectCollision(Bitmap bm);
private:
	Mat bm;
	Vector2 s;
	Vector2* p;
	void createBitmap(std::string location, Vector2 size);
	vector<Vector2> detectOverlap(Bitmap bm, Bitmap bm2, int reversed = 0);
	

};

#endif // !1
