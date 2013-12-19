#include "Vector2.h"

Vector2::Vector2()
{
	Vector2(0, 0);
}

Vector2::Vector2(double vx, double vy)
{
	x = vx;
	y = vy;
}

Vector2 Vector2::operator+(Vector2 v)
{
	Vector2 temp;
	temp.x = x + v.x;
	temp.y = y + v.y;
	return temp;
}

void Vector2::operator+=(Vector2 v)
{
	x += v.x;
	y += v.y;
}

Vector2 Vector2::operator-(Vector2 v)
{
	Vector2 temp;
	temp.x = x - v.x;
	temp.y = y - v.y;
	return temp;
}

void Vector2::operator-=(Vector2 v)
{
	x -= v.x;
	y -= v.y;
}

// Scalar product
Vector2 Vector2::operator*(double v)
{
	Vector2 temp;
	temp.x = x * v;
	temp.y = y * v;
	return temp;
}

void Vector2::operator*=(double v)
{
	Vector2 temp;
	x *= v;
	y *= v;
}

double Vector2::dot(Vector2 v)
{
	return (v.x * x) + (v.y * y);
}

double Vector2::magnitude()
{
	return sqrt(dot(*this));
}

void Vector2::normalize()
{
	double m = magnitude();
	x = x / m;
	y = y / m;
}

