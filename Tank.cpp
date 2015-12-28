
#include "Tank.h"
#include <cmath>
#include <iostream>

const float Tank::MAX_SPEED = 0.1;
const float Tank::ACCELERATION = 1;
const float Tank::SPEED_DIFFRENTIAL = 0.01;
const float Tank::TURN_DIFFRENTIAL = 60;
const float Tank::BRAKING_DIFFRENTIAL = 0.002;

Tank::Tank()
{
	speed = 0;
	position = { 0,0,0 };
	angle = { 0,0,0 };
}

void Tank::accelerate(int direction)
{
	lastAccelerate = std::chrono::high_resolution_clock::now();
	if (speed + SPEED_DIFFRENTIAL*direction<MAX_SPEED
		&& speed + SPEED_DIFFRENTIAL*direction>-MAX_SPEED)
		speed += SPEED_DIFFRENTIAL*direction;
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

	position.x = position.x + speed*cos(angle.y* (3.1415 / 180.0));
	position.z = position.z - speed*sin(angle.y* (3.1415 / 180.0));
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastAccelerate).count()>500)
	{
		if (speed - BRAKING_DIFFRENTIAL > 0) speed = speed - BRAKING_DIFFRENTIAL;
		if (speed + BRAKING_DIFFRENTIAL < 0) speed = speed + BRAKING_DIFFRENTIAL;
		if (speed<BRAKING_DIFFRENTIAL && speed>-BRAKING_DIFFRENTIAL) speed = 0;
	}




	glPushMatrix();
	GLfloat torus_diffuse[] = { 0.0, 1, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, torus_diffuse);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(angle.y, 0, 1, 0);
	glutSolidCube(1.5);
	glPopMatrix();
}