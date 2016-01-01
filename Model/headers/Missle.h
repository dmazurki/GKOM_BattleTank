#pragma once
#pragma once
#include "SceneObject.h"

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "../../glut.h"
#endif

#include <chrono>


class Missle : public SceneObject
{

public:
	static const float EARTH_ACCELERATION;


	Missle(float speed, Vector3D beginPos, Vector3D beginAngle);
	~Missle();
	

	void update();
	void draw();

private:
	float speedH;
	float speedV;
	int timeElapsed;

	GLUquadricObj *missleQuadric;


};

