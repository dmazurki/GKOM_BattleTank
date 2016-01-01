#include "../headers/Environment.h"
#include "../../Assets/headers/Assets.h"
#include <iostream>


Environment::Environment(GLfloat size_) : size(size_)
{
}
void Environment::refresh()
{
	if (isWired())
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	const GLfloat ChromeAmbient[4] =
	{
		0.450000, 0.450000, 0.450000, 1.000000
	};

	const GLfloat ChromeDiffuse[4] =
	{
		0.400000, 1.00000, 0.400000, 1.000000
	};

	const GLfloat ChromeSpecular[4] =
	{
		0.774597, 0.774597, 0.774597, 1.000000
	};

	const GLfloat ChromeShininess = 76.8;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ChromeAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ChromeDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ChromeSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, ChromeShininess);

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, Assets::getAssets().grassTexture);

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



