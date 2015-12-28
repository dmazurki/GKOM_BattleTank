#pragma once
#include "SOIL.h"
#include "glut.h"
class Ground
{
	GLfloat size;
	GLuint texture;
public:
    Ground(GLfloat size);
	void refresh();
};