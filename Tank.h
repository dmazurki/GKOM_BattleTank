#pragma once
#include "SceneObject.h"
#include "glut.h"
#include <chrono>


class Tank : public SceneObject
{
private:
	float speed;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastAccelerate;
public:
	static const float MAX_SPEED;
	static const float ACCELERATION;
	static const float SPEED_DIFFRENTIAL;
	static const float TURN_DIFFRENTIAL;
	static const float BRAKING_DIFFRENTIAL;


	Tank();
	void accelerate(int direction);
	void turn(int direction);

	void refresh();
	
};
