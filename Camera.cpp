#include "Camera.h"

Camera::Camera(SceneObject * followedObject_, GLfloat distance_)
	:followedObject(followedObject_),distance(distance_)
{
	angle = followedObject_->angle;
	position.x = followedObject_->position.x + 3;
	position.y = followedObject_->position.y + 3;
	position.z = followedObject_->position.z + 3;

}

void Camera::refresh()
{

}