#include "../headers/Camera.h"
#include "../../Logic/headers/Game.h"
#include <iostream>
#include <cmath>

const float Camera::SPEED = 2;
const int Camera::REFRESHING_DESIRED_POSITION_RATE = Game::UPS/2;

Camera::Camera(SceneObject * followedObject_, GLfloat distance_)
	:followedObject(followedObject_),distance(distance_),setting(1)
{
	angle = followedObject_->angle;
	position.x = followedObject_->position.x + distance/2;
	position.y = followedObject_->position.y + distance;
	position.z = followedObject_->position.z + distance/2;

	updatesSinceRefresh = 0;

}
void Camera::updatePosition()
{
	if(updatesSinceRefresh>REFRESHING_DESIRED_POSITION_RATE)
	{
		desiredAngle.y = followedObject->angle.y;
		updatesSinceRefresh=0;
	}
	if(angle.y+SPEED<desiredAngle.y)
	{
		if(desiredAngle.y-angle.y<180)
			angle.y+=SPEED;
		else
			angle.y=angle.y-SPEED;

	}
	else
		if(angle.y-SPEED>desiredAngle.y)
		{
			if(angle.y - desiredAngle.y<180)
				angle.y-=SPEED;
			else
				angle.y+=SPEED;
		}
	while (angle.y > 360) angle.y -= 360;
	while (angle.y < 0) angle.y += 360;

	position.x =followedObject->position.x - setting*distance*cos(angle.y* (3.1415 / 180.0));
	position.z = followedObject->position.z + setting*distance*sin(angle.y* (3.1415 / 180.0));
	position.y = followedObject->position.y + 3;
	updatesSinceRefresh++;
}
void Camera::refresh()
{
	gluLookAt(
		position.x,
		position.y,
		position.z,
		followedObject->position.x,
		followedObject->position.y,
		followedObject->position.z,
		0.0,
		1.0,
		0.0);
}

void Camera::changeSetting()
{setting = setting*(-1); }