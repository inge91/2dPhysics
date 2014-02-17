#ifndef BITMAP_H
#define BITMAP_H

#include<iostream>
#include"Vector2.h"
#include"opencv\cv.h"
#include"opencv2\opencv.hpp"
#include"Drawable.h"
using namespace cv;



class Bitmap 
{
	
public:
	Bitmap(std::string location, Vector2 size);
private:
	Mat bm;
	void createBitmap(std::string location, Vector2 size);

};

#endif // !1
