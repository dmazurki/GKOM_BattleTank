#include "Environment.h"
#include "../Assets/Assets.h"
#include "../Logic/Game.h"
#include <iostream>
#include <chrono>
#include <random>


Environment::Environment(GLfloat size_) : size(size_)
{
	sky = gluNewQuadric();
	gluQuadricNormals(sky, GLU_SMOOTH);
	gluQuadricTexture(sky, GL_TRUE);
	gluQuadricOrientation(sky, GLU_INSIDE);

}

Environment::~Environment()
{
	gluDeleteQuadric(sky);
	for(auto tree : trees)
		delete tree;
}

void Environment::draw()
{


//	glPushMatrix();
//			glEnable(GL_TEXTURE_2D);
//			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//
//			glBindTexture(GL_TEXTURE_2D, Assets::getAssets().skyTexture);
//	glRotatef(-90,1,0,0);
//
//	gluCylinder(sky, Game::size + RING2, Game::size + RING2, 200, 15, 15);
//
//
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, Assets::getAssets().wallTexture);

	glMatrixMode (GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity ();
	glScalef (20, 1, 1);

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glRotatef(-90,1,0,0);
	gluCylinder(sky, Game::size+ RING1 , Game::size + RING1, 10, 10, 10);
	glPopMatrix();

	glMatrixMode (GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_TEXTURE_2D);



	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, Assets::getAssets().groundTexture);


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-(Game::size + RING2) * 1.4, 0.0, -(Game::size + RING2) * 1.4);
		glTexCoord2f(0.0, 10.0); glVertex3f(-(Game::size + RING2) * 1.41, 0.0, (Game::size + RING2) * 1.4);
		glTexCoord2f(10.0, 10.0); glVertex3f((Game::size + RING2) * 1.4, 0.0, (Game::size + RING2) * 1.4);
		glTexCoord2f(10.0, 0.0); glVertex3f((Game::size + RING2) * 1.41, 0.0, -(Game::size + RING2) * 1.4);
	glEnd();


	glPopMatrix();
		
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}


const GLfloat Environment::RING1 = 10;
const GLfloat Environment::RING2 = 20;