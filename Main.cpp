#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include "Ground.h"
#include "Tank.h"
#include "Camera.h"
#include "Sun.h"
#include <iostream>

Ground * gr;
Tank * t;
Camera * c;
Sun * s;

void init()
{
	gr = new Ground(100);
	t = new Tank();
	c = new Camera(t, 3);
	s = new Sun();



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

void displayObjects(int frame_no)
{
	GLfloat torus_diffuse[] = { 0.7, 0.7, 0.0, 1.0 };
	GLfloat cube_diffuse[] = { 0.0, 0.7, 0.7, 1.0 };
	GLfloat sphere_diffuse[] = { 0.7, 0.0, 0.7, 1.0 };
	GLfloat octa_diffuse[] = { 0.7, 0.4, 0.4, 1.0 };


	s->refresh();
	glPushMatrix();
	glTranslatef(-0.80, 0.35, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, torus_diffuse);
	glutSolidTorus(0.275 / 2, 0.85 / 2, 10, 10);
	glPopMatrix();


	gr->refresh();
	t->refresh();
	

	glPopMatrix();
}

void display()
{
	static int frame_no = 0;
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//if (frame_no<360) frame_no++; else frame_no = 0;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	c->refresh();
	glRotatef((GLfloat)frame_no, 0, 1.0,0);

	glMatrixMode(GL_MODELVIEW);
	displayObjects(frame_no);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

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
		// odsuniecie oka obserwatora od srodka ukladu wspolrzednych
		
		glMatrixMode(GL_MODELVIEW);
	}
}


void keyPressed(unsigned char key, int x, int y) {
	//std::cout << "klawisz: " << (int) key << std::endl;
	if (key == 'w') {
		std::cout << "w"<<std::endl;
		t->move(1);
	}
	if (key == 's') {
		std::cout << "s" << std::endl;
		t->move(-1);
	}
	if (key == 'a') {
		std::cout << "a" << std::endl;
		t->turn(-1);
	}
	if (key == 'd') {
		std::cout << "d" << std::endl;
		t->turn(1);
	}
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);

	glutCreateWindow("GPOB: OpenGL");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(display);

	init();

	glutMainLoop();
	delete gr;
	delete t;

	return 0;
}
