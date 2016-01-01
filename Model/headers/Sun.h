#pragma once

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "../../glut.h"
#endif

#include "SceneObject.h"

class Sun :public SceneObject
{
public:
	Sun();
	void refresh();

};