
#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include <windows.h>
#include "glut.h"
#endif

#include "Logic/headers/Game.h"


Game * game;
void init()
{
	game = new Game();

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_NORMALIZE);
}



void display()
{
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	game->refresh();

	glFlush();
	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h)
{
	if (h > 0 && w > 0) {
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) {
			glFrustum(-5, 5, -5*h / w, 5*h / w, 3.0, 40.0);
		}
		else {
			glFrustum(-3*w / h, 3*w / h, -1, 5, 6, 150);
			//glOrtho( -5*w/h, 5*w/h, -3, 5,1,10 );

		}
		
		glMatrixMode(GL_MODELVIEW);
	}
}


void keyPressed(unsigned char key, int x, int y) {
	game->keyPressed(key);
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Damian Mazurkiewicz: BattleTank");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(display);

	init();

	glutMainLoop();
	delete game;

	return 0;
}


