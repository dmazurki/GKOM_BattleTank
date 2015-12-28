#pragma once

#include "SceneObject.h"
#include "glut.h"

class Camera : SceneObject
{
public:
	Camera(SceneObject * followedObject, GLfloat distance);

	void refresh();

private:
	SceneObject* followedObject;
	GLfloat distance;
};