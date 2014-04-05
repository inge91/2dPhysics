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
	
	// Initialize barriers
	StaticElement *s = new StaticElement(new Vector2(3,9), Vector2(20, 0.5));
	objs.add_object(static_cast<Object*>(s));
	
}

void keyPress(unsigned char key, int x, int y)
{
	switch(key){
	case 114: 
		objs.destroy_objects();
		break;
	}
}

void mouseClick(int button, int state, int x, int y)
{
	// Create particle at the position :D
	if(state == GLUT_UP)
	{
		Vector2 pos(x/d, y/d);
		Vector2 *p = &pos;
		if(button == GLUT_RIGHT_BUTTON)
		{
			//BowlingBall *b = new BowlingBall(pos, Vector2(0,0));
			BowlingBall *b = new BowlingBall(Vector2(0,0), Vector2(0,0));
			objs.add_object(static_cast<Object*>(b));
		}
		else{
			Box *b = new Box(pos, Vector2(0,0));
			objs.add_object(static_cast<Object*>(b));

		}
		
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
// FIXME: Seperate file for Sleep definition
#ifdef _WIN32
		Sleep((1/fps) * 1000 - timeInterval);
#else
        usleep((1/fps) * 1000 - timeInterval);
#endif

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
	glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);

	glutDisplayFunc(display);				
	glutIdleFunc(idle);						
   
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(keyPress);
	initialize();
	glutMainLoop();										
	return 0;
}

