#pragma once
#include "SceneObject.h"

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "glut.h"
#endif

#include "Missle.h"
#include <chrono>

class Tank : public SceneObject
{

public:
	enum Movement {MOVE_FRONT = 1, BRAKE = 0, MOVE_BACK = -1};
	static const float MAX_SPEED;
	static const float SPEED_DIFFRENTIAL;
	static const float TURN_DIFFRENTIAL;
	static const float BRAKING_DIFFRENTIAL;

	static const GLfloat CATERPILLAR_VERTEX[];
	static const GLfloat CATERPILLAR_TEXTURE[];
	static const GLubyte CATERPILLAR_INDICES[];

	static const GLfloat BOX_VERTEX[];
	static const GLfloat BOX_TEXTURE[];
	static const GLubyte BOX_INDICES[];


	Tank();
	Tank(Vector3D beginPosition);
	~Tank();
	void move(int direction);
	void turn(int direction);
	void bounce(SceneObject * other);
	Missle * shoot();

	GLfloat getSpeed();
	GLfloat getAngle();


	void update();
	void draw();
private:
	float speed;

	float bounceSpeed;
	float bounceAngle;

	Movement movement;
	GLUquadricObj *towerQuadric;
};


