#include "Header.h"
const int XSize = 640;
const int YSize = 480;

// 50 pixels is a meter
double d = 50;

// Desired framerate
int fps = 60;

//int frameCount = 0;
int previousTime;

ObjectHandler objs;


double t;

Vector2 f;

void display() 
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     // Clear Screen and Depth Buffer
	glLoadIdentity();
	
	// Draw particles and their position
	objs.draw_objects();

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

void mouseClick(int button, int state, int x, int y)
{
	// Create particle at the position :D
	if(state == GLUT_UP)
	{
		Vector2 pos(x/d, y/d);
		Vector2 *p = &pos;
		
		BowlingBall *b = new BowlingBall(pos, Vector2(0,0));
		objs.add_object(static_cast<Object*>(b));
		
	}

}

void calculateFPS()
{

	// Running time
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
 
    //  Calculate time passed
    int timeInterval = currentTime - previousTime;
 
	// In case the interval is shorter than the desired fps
	// wait
	if(timeInterval < (1/fps) * 1000)
	{
		Sleep((1/fps) * 1000 - timeInterval);
	}
	// Else just use the time interval
	else{
		t = timeInterval/1000.0;
	}
	previousTime = currentTime;
}



void idle (void)
{
    calculateFPS();
 
	// Update physics
	objs.update_physics(t);	

    //  Call display function (draw the current frame)
    glutPostRedisplay ();
}



int main(int argc, char **argv)
{

		
	glutInit(&argc, argv);                                    
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 

	glutInitWindowSize(XSize, YSize);
	glutCreateWindow("Physiscs test");
	glutSetCursor(GLUT_CURSOR_NONE);

	glutDisplayFunc(display);				
	glutIdleFunc(idle);						
   
	glutMouseFunc(mouseClick);
	initialize();
	glutMainLoop();										
	return 0;
}

