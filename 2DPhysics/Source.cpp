#include "Header.h"
const int XSize = 640;
const int YSize = 480;

vector<Particle> p_list;

Vector2 f;

void display() 
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     // Clear Screen and Depth Buffer
	glLoadIdentity();
 
	for(auto p: p_list)
	{
		Vector2 pos = p.getPosition();

		glBegin(GL_POINTS);
		glVertex2f(pos.x, pos.y);
		glEnd();
		p.updatePhysics();
	}
 
	glutSwapBuffers();
}


void initialize () 
{
	 glMatrixMode (GL_PROJECTION);
	 
	 glLoadIdentity ();
	 
	 glOrtho (0, XSize, YSize, 0, 0, 1);
	 
	 glMatrixMode (GL_MODELVIEW);
	 glDisable(GL_DEPTH_TEST);
	
	// Start the timer
}

void update_orientation(int x, int y)
{
   glFlush();
   display();
}

void mouseClick(int button, int state, int x, int y)
{
	// Create particle at the position :D
	if(state == GLUT_UP)
	{
		Vector2 pos(x, y);
		Particle p =  Particle(pos, Vector2(4,0), 5);
		p_list.push_back(p);
	}

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                                    
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 

	glutInitWindowSize(XSize, YSize);
	glutCreateWindow("Physiscs test");
	glutSetCursor(GLUT_CURSOR_NONE);

	glutDisplayFunc(display);				
	glutIdleFunc(display);						
    glutPassiveMotionFunc(update_orientation);
	glutMouseFunc(mouseClick);
	initialize();
	glutMainLoop();										
	return 0;
}

