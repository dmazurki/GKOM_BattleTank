#pragma once
#include "../../SOIL.h"
#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif
#include "SceneObject.h"
class Environment : public SceneObject
{
	GLfloat size;
	GLUquadricObj * sky;
public:
	Environment(GLfloat size);
	~Environment();
	void draw();
};