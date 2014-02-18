#ifndef SPRITE_H
#define SPRITE_H 
#include <stdio.h>
#include <iostream>
#include "SOIL.h"

#include "Vector2.h"
#include "Drawable.h"
#include "GL\glut.h"
#include "GL\freeglut.h"
#include "Bitmap.h"
class Sprite: public Drawable{
	
	public:
		Sprite(std::string location, Vector2 *pos, Vector2 s);
	private:
		
		Bitmap bm;
		GLuint texture;
		void loadTexture(std::string location);
		// Draw the sprite
		void draw();
		Vector2 *p;
		Vector2 size;
};

#endif SPRITE_H