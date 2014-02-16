#include "Sprite.h"


Sprite::Sprite(std::string location, Vector2 *pos, Vector2 s)
	: size(s.x, s.y)
{
	p = pos;
	cout<<p->x<<endl;
	cout<<p->y<<endl;
	loadTexture(location);
	
}

// FIXME make this its own class?
void Sprite::loadTexture(std::string location)
{
	
	texture = SOIL_load_OGL_texture(location.c_str(), 
						SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_POWER_OF_TWO
				| SOIL_FLAG_MIPMAPS
				| SOIL_FLAG_MULTIPLY_ALPHA
				| SOIL_FLAG_COMPRESS_TO_DXT
				| SOIL_FLAG_DDS_LOAD_DIRECT
				| SOIL_FLAG_INVERT_Y
				);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texture);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
	//			  GL_UNSIGNED_BYTE, image);
}


void Sprite::draw()
{

	cout<<*p<<endl;
	double px = Drawable::meters2Pixels(p->x);
	double py = Drawable::meters2Pixels(p->y);
	double vecx = Drawable::meters2Pixels(size.x);
	double vecy = Drawable::meters2Pixels(size.y);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable (GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	//Size still to be determined
	glTexCoord2f(0, 0); glVertex2f(px - vecx/2, py - vecy/2);
	glTexCoord2f(0, 1); glVertex2f(px - vecx/2, py + vecy/2);
	glTexCoord2f(1, 1); glVertex2f(px + vecx/2, py + vecy/2);
	glTexCoord2f(1, 0); glVertex2f(px + vecx/2, py - vecy/2);
	glEnd();
}