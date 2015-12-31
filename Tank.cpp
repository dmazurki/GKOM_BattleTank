
#include "Tank.h"
#include <cmath>
#include <iostream>
#include "SOIL.h"

const float Tank::MAX_SPEED = 0.3;
const float Tank::ACCELERATION = 1;
const float Tank::SPEED_DIFFRENTIAL = 0.01;
const float Tank::TURN_DIFFRENTIAL = 10;
const float Tank::BRAKING_DIFFRENTIAL = 0.01;

Tank::Tank()
{
	speed = 0;
	position = { 0,0,0 };
	angle = { 0,0,0 };

	movement = BRAKE;
	
	towerQuadric = gluNewQuadric();
	gluQuadricNormals(towerQuadric, GLU_SMOOTH);
	gluQuadricTexture(towerQuadric, GL_TRUE);

	std::cout << "Loading ground texture...\n";
	this->khaki = SOIL_load_OGL_texture
		(
			"Assets/khaki.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
	if (0 == this->khaki)
	{
		std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
	}

}

void Tank::move(int direction)
{
	if (direction == 1)
	{
		if (movement == MOVE_BACK)
			movement = BRAKE;
		else
			if (movement == BRAKE)
				movement = MOVE_FRONT;
	}
	else
	if (direction == -1)
	{
		if (movement == BRAKE)
			movement = MOVE_BACK;
		else
		if (movement == MOVE_FRONT)
			movement = BRAKE;
	}

	
}
void Tank::turn(int direction)
{

	angle.y = (angle.y - direction*TURN_DIFFRENTIAL*speed);
	
	while (angle.y > 360) angle.y -= 360;
	while (angle.y < 0) angle.y += 360;
	std::cout << angle.y;
	
}

void Tank::refresh()
{
	if (movement == BRAKE)
	{
		if (speed - BRAKING_DIFFRENTIAL > 0) speed -= BRAKING_DIFFRENTIAL;
		else
			if (speed > 0) speed = 0;
			else
				if (speed + BRAKING_DIFFRENTIAL < 0) speed += BRAKING_DIFFRENTIAL;
				else
					if (speed < 0) speed = 0;
	}
	else
	{
		if (speed + SPEED_DIFFRENTIAL*movement < MAX_SPEED &&
			speed + SPEED_DIFFRENTIAL*movement > -MAX_SPEED)
		{
			std::cout << "speed" << speed; 
			speed += SPEED_DIFFRENTIAL*movement;
		}
		

	}

	position.x = position.x + speed*cos(angle.y* (3.1415 / 180.0));
	position.z = position.z - speed*sin(angle.y* (3.1415 / 180.0));
	

	glPushMatrix();
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

	glTranslatef(position.x, position.y, position.z);
	glRotatef(angle.y, 0, 1, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, khaki);

	//tower
	glPushMatrix();
	glTranslatef(0, 1.25, 0);
	gluSphere(towerQuadric, 0.7, 10, 10);
	glPopMatrix();


	//gun
	glPushMatrix();
	glTranslatef(0, 1.6, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(towerQuadric, 0.1, 0.1, 1, 10, 1);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);


	//caterpillars
	drawCaterpillar(true);
	drawCaterpillar(false);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Tank::BOX_VERTEX);

	glPushMatrix();
	glTranslatef(0.0, 0.75, 0.0);
	glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_BYTE, Tank::BOX_INDICES);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);



	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	

	//glutSolidCube(1.5);

	glPopMatrix();
}
Tank::~Tank() {}

void Tank::drawCaterpillar(bool right)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, Tank::CATERPILLAR_VERTEX);

	glPushMatrix();
	glTranslatef(-1.5, 0.5, 1.0);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, Tank::CATERPILLAR_INDICES);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 0.5, -1);
	glRotatef(180, 0.0, 1.0, 0.0);
	glTranslatef(-1.5, 0, 0);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, Tank::CATERPILLAR_INDICES);
	glPopMatrix();


	glDisableClientState(GL_VERTEX_ARRAY);

}




const GLfloat Tank::CATERPILLAR_VERTEX[] = {
	//right side 

	0.0,	0.0,	 0.0,	//0
	0.5,	-0.5,	 0.0,	//1
	0.5,	0.0,	0.0,	//2

	0.5,	-0.5,	0.0,	//3
	2.5,	-0.5,	 0.0,	//4
	0.5,	0.0,	0.0,	//5

	2.5,	-0.5,	0.0,	//6
	2.5,	0.0,	0.0,	//7
	0.5,	0.0,	0.0,	//8

	2.5,	-0.5,	0.0,	//9
	3.0,	0.0,	0.0,	//10
	2.5,	0.0,	0.0,	//11

							//back

	0.0,	0.0,	-0.3,	//12
	0.5,	-0.5,	-0.3,	//13
	0.5,	-0.5,	0,		//14

	0.5,	-0.5,	0,		//15
	0.0,	0.0,	0.0,	//16
	0.0,	0.0,	-0.3,	//17

							//front

	3.0,	0.0,	0.0,	//18
	2.5,	-0.5,	0.0,	//19
	3.0,	0.0,	-0.3,	//20

	2.5,	-0.5,	0.0,	//21
	2.5,	-0.5,	-0.3,	//22
	3,0,	0.0,	-0.3,	//23


};

const GLubyte Tank::CATERPILLAR_INDICES[] = {
	0,	1,	2,
	1,	4,	2,
	4,	7,	2,
	4,	10,	7,

	12, 13, 3,
	3,	0,	12,

	10, 9,	20,
	9,	22, 20,
};

const GLfloat Tank::BOX_VERTEX[] =
{
	-1.5,	0.25,	-1,	//0
	-1.5,	-0.25,	-1,	//1
	-1.5,	-0.25,	1,	//2
	-1.5,	0.25,	-1,	//3
	-1.5,	-0.25,	1,	//4
	-1.5,	0.25,	1,	//5

	-1.5,	0.25,	1,	//6
	-1.5,	-0.25,	1,	//7
	1.5,	0.25,	1,	//8
	-1.5,	-0.25,	1,	//9
	1.5,	-0.25,	1,	//10
	1.5,	0.25,	1,	//11

	1.5,	-0.25,	1,	//12
	1.5,	-0.25,	-1,	//13
	1.5,	0.25,	1,	//14
	1.5,	0.25,	1,	//15
	1.5,	-0.25,	-1,	//16
	1.5,	0.25,	-1,	//17

	1.5,	-0.25,	-1,	//18
	-1.5,	-0.25,	-1,	//19
	-1.5,	0.25,	-1,	//20
	1.5,	-0.25,	-1,	//21
	-1.5,	0.25,	-1,	//22
	1.5,	0.25,	-1,	//23

	-1.5,	0.25,	1,	//24
	1.5,	0.25,	1,	//25
	1.5,	0.25,	-1,	//26

	-1.5,	0.25,	1,	//27
	1.5,	0.25,	-1,	//28
	-1.5,	0.25,	-1,	//29

};

const GLubyte Tank::BOX_INDICES[] =
{
	0,	1,	2,
	0,	2,	5,

	5,	2,	8,
	2,	10,	8,

	10, 13,	11,
	8,  13, 17,

	13,	1,	0,
	13, 0, 17,

	5,	8,	23,
	5,	23,	0,

};