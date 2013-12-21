#ifndef HEADER_H
#define HEADER_H
#include "GL\glut.h"
#include "GL\freeglut.h"
#include <stdio.h>
#include <vector>
#include <time.h>
//#include "Vector2.h"
#include "Particle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ObjectHandler.h"
#include "Object.h"

using namespace std;

void display() ;

void initialize ();

void update_orientation(int x, int y);

void mouseClick(int button, int state, int x, int y);





#endif