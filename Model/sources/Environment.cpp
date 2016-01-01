#include "../headers/Environment.h"
#include "../../Assets/headers/Assets.h"
#include <iostream>


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
}

void Environment::draw()
{


	glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBindTexture(GL_TEXTURE_2D, Assets::getAssets().skyTexture);

			glTranslatef(0,-1,0);
			glRotatef(-90,1,0,0);
			gluCylinder(sky, 50, 50, 100,15,15);

			glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, Assets::getAssets().groundTexture);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex3f(-size/2, 0.0, -size / 2);
		glTexCoord2f(0.0, 10.0); glVertex3f(-size / 2, 0.0, size / 2);
		glTexCoord2f(10.0, 10.0); glVertex3f(size / 2, 0.0, size / 2);
		glTexCoord2f(10.0, 0.0); glVertex3f(size / 2, 0.0, -size / 2);
	glEnd();


	glPopMatrix();
		
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}



