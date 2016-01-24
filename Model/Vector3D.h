#pragma once

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "../../glut.h"
#endif

struct Vector3D
{
	GLfloat x, y, z;
	Vector3D(GLfloat x_ = 0, GLfloat y_ = 0, GLfloat z_ = 0 ): x(x_),y(y_),z(z_) {}
};