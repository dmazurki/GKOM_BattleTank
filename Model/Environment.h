#pragma once

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif

#include <list>
#include "SceneObject.h"
#include "Tree.h"

class Environment : public SceneObject
{
	static const GLfloat RING1;
	static const GLfloat RING2;

	GLfloat size;
	GLUquadricObj * sky;
	std::list<Tree*> trees;

	void initTrees();

public:
	Environment(GLfloat size);
	~Environment();
	void draw();


};