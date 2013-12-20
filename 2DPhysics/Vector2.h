#ifndef VECTOR2_H
#define VECTOR2_H
#include<iostream>
#include<math.h>
using namespace std;

class Vector2
{
public:	
	double x;
	double y;
	Vector2();
	Vector2(double vx, double vy);

	Vector2 operator+(Vector2 v);
	void operator+=(Vector2 v);

	Vector2 operator-(Vector2 v);
	void operator-=(Vector2 v);

	// multiplication of vectors (is this useful?)
	Vector2 operator*(double v);
	void operator*=(double v);

	// dot product
	double dot(Vector2 v);

	// vector magnitude
	double magnitude();

	// vector normalize
	void normalize();

	friend ostream &operator<<(ostream &os, Vector2 &v);	
};
#endif