#pragma once

#include "SceneObject.h"

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif

class Camera
{
public:
	static const float SPEED;
	static const int REFRESHING_DESIRED_POSITION_RATE;

	Camera(SceneObject * followedObject, GLfloat distance);

	void updatePosition();
	void refresh();
	void changeSetting();
	void draw(){}

private:
	SceneObject* followedObject;

	Vector3D position;
	Vector3D angle;
	Vector3D desiredAngle;

	int updatesSinceRefresh;
	int setting;

	GLfloat distance;
};