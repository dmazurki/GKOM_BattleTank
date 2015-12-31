#pragma once
#include "SceneObject.h"
#include "glut.h"
#include <chrono>


class Tank : public SceneObject
{

public:
	enum Movement {MOVE_FRONT = 1, BRAKE = 0, MOVE_BACK = -1};
	static const float MAX_SPEED;
	static const float ACCELERATION;
	static const float SPEED_DIFFRENTIAL;
	static const float TURN_DIFFRENTIAL;
	static const float BRAKING_DIFFRENTIAL;


	static const GLfloat CATERPILLAR_VERTEX[];
	static const GLubyte CATERPILLAR_INDICES[];

	static const GLfloat BOX_VERTEX[];
	static const GLubyte BOX_INDICES[];



	Tank();
	~Tank();
	void move(int direction);
	void turn(int direction);

	void refresh();

private:
	float speed;
	GLuint khaki;
	Movement movement;
	GLUquadricObj *towerQuadric;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastAccelerate;

	void  drawCaterpillar(bool right);
	
};


