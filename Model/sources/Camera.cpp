#include "../headers/Camera.h"
#include <iostream>
#include <cmath>


Camera::Camera(SceneObject * followedObject_, GLfloat distance_)
	:followedObject(followedObject_),distance(distance_)
{
	angle = followedObject_->angle;
	position.x = followedObject_->position.x + distance/2;
	position.y = followedObject_->position.y + distance;
	position.z = followedObject_->position.z + distance/2;

}
void Camera::updatePosition()
{
	GLfloat  angle = followedObject->angle.y;

	position.x = followedObject->position.x - 3;
	position.z = followedObject->position.z + 3;
	position.y = followedObject->position.y + 3.4;
}
void Camera::refresh()
{
		
//	position.x =followedObject->position.x -distance*cos(angle* (3.1415 / 180.0));
//	position.z = followedObject->position.z + distance*sin(angle* (3.1415 / 180.0));
//	position.y = followedObject->position.y + 4;

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