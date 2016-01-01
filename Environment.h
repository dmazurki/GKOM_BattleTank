#pragma once
#include "SOIL.h"
#include "glut.h"
#include "SceneObject.h"
class Environment : public SceneObject
{
	GLfloat size;
	GLuint texture;
public:
	Environment(GLfloat size);
	void refresh();
};