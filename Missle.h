#pragma once
#pragma once
#include "SceneObject.h"
#include "glut.h"
#include <chrono>


class Missle : public SceneObject
{

public:
	static const GLfloat Missle::MISSLE_AMBIENT[];
	static const GLfloat Missle::MISSLE_DIFUSE[];
	static  const GLfloat Missle::MISSLE_SPECULAR[];
	static const GLfloat Missle::MISSLE_SHININESS;
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

