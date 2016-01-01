#include "../headers/Missle.h"
#include <cmath>

Missle::Missle(float beginSpeed, Vector3D beginPos, Vector3D beginAngle)
{
	position = beginPos;
	angle = beginAngle;
	speed = beginSpeed;
	speedH = beginSpeed*cos((beginAngle.x* 3.1415) / 180);
	speedV = beginSpeed*sin((beginAngle.y* 3.1415) / 180);

	timeElapsed = 0;
	quadric = gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
}

Missle::~Missle()
{
	gluDeleteQuadric(quadric);
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
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MISSLE_AMBIENT);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MISSLE_DIFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MISSLE_SPECULAR);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MISSLE_SHININESS);

	glTranslatef(position.x, position.y, position.z);

	gluSphere(quadric, 0.2, 10, 10);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPopMatrix();
}


const GLfloat Missle::MISSLE_AMBIENT[4] =
{
	0.450000, 0.450000, 0.450000, 1.000000
};

const GLfloat Missle::MISSLE_DIFUSE[4] =
{
	0.400000, 1.00000, 0.400000, 1.000000
};

const GLfloat Missle::MISSLE_SPECULAR[4] =
{
	0.774597, 0.774597, 0.774597, 1.000000
};

const GLfloat Missle::MISSLE_SHININESS = 76.8;
const GLfloat Missle::EARTH_ACCELERATION = 0.02;