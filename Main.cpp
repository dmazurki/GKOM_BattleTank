
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


	GLfloat mat_ambient[] = { 1.0, 1.0,  1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0,  1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 10.0, 0.0, 1.0 };
	//GLfloat light_position[] = { 0.1, 1.0, 0.1, 0.0 };

	GLfloat lm_ambient[] = { 0.3, 0.3,  0.3, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);
		


	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

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
			glFrustum(-2.5, 2.5, -2.5*h / w, 2.5*h / w, 6.0, 40.0);
		}
		else {
			glFrustum(-2.5*w / h, 2.5*w / h, -2.5, 2.5, 2, 50);
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
