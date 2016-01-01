#pragma once

#include "SceneObject.h"

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif

class Camera : SceneObject
{
public:
	Camera(SceneObject * followedObject, GLfloat distance);

	void updatePosition();
	void refresh();

private:
	SceneObject* followedObject;
	GLfloat distance;
};