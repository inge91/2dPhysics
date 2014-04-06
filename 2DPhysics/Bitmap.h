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
    Vector2* p;
	Vector2 s;
	Bitmap(std::string location, Vector2 size);
	vector<Vector2> detectCollision(Bitmap bm, Vector2 p1, Vector2 p2);
    void setPosition(Vector2* pos);

private:
	Mat bm;
	void createBitmap(std::string location, Vector2 size);
	vector<Vector2> detectOverlap(Bitmap bm, Bitmap bm2, Vector2 pf, Vector2 ps, int reversed = 0);
	

};

#endif // !1
