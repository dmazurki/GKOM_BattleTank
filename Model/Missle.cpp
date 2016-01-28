#include "Missle.h"
#include "../Assets/Assets.h"
#include <cmath>

Missle::Missle(float beginSpeed, Vector3D beginPos, Vector3D beginAngle)
{
	position = beginPos;
	angle = beginAngle;
	speedH = beginSpeed*cos((beginAngle.x* 3.1415) / 180);
	speedV = beginSpeed*sin((beginAngle.y* 3.1415) / 180);
	collisionRadius = 0.1;

	timeElapsed = 0;
	missleQuadric = gluNewQuadric();
	gluQuadricNormals(missleQuadric, GLU_SMOOTH);
	gluQuadricTexture(missleQuadric, GL_TRUE);

}

Missle::~Missle()
{
	gluDeleteQuadric(missleQuadric);
}

void Missle::update()
{
	position.x = position.x + speedH*cos(angle.y* (3.1415 / 180.0));
	position.z = position.z - speedH*sin(angle.y* (3.1415 / 180.0));
	position.y = position.y + speedV*sin(angle.x* (3.1415 / 180.0)) - EARTH_ACCELERATION*timeElapsed;
	++timeElapsed;
}


void Missle::draw()
{
	if (isWired()) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	glPushMatrix();


	glTranslatef(position.x, position.y, position.z);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,Assets::getAssets().missleTexture);

	gluSphere(missleQuadric, 0.2, 10, 10);
	glDisable(GL_TEXTURE_2D);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
}

const float Missle::EARTH_ACCELERATION = 0.007;

