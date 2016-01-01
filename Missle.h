#pragma once
#pragma once
#include "SceneObject.h"
#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif
#include <chrono>


class Missle : public SceneObject
{

public:
	static const GLfloat MISSLE_AMBIENT[];
	static const GLfloat MISSLE_DIFUSE[];
	static  const GLfloat MISSLE_SPECULAR[];
	static const GLfloat MISSLE_SHININESS;
	static const float EARTH_ACCELERATION;


	Missle(float speed, Vector3D beginPos, Vector3D beginAngle);
	~Missle();
	

	void update();
	void draw();

private:
	float speed;
	float speedH;
	float speedV;
	int timeElapsed;

	GLUquadricObj *quadric;


};

