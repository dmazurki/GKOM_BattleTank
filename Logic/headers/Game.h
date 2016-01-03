#pragma once
#include <list>
#include "../../Model/headers/SceneObject.h"
#include "../../Model/headers/Tank.h"
#include "../../Model/headers/Missle.h"
#include "../../Model/headers/Camera.h"
#include "../../Model/headers/Environment.h"
#include "../../Assets/headers/ComputerOpponent.h"

class Game
{
public:
	static const int UPS = 30;
	static const int MILLISECONDS_INTERSPACE = 1000 / UPS;
	static const GLfloat size;


	Game();
	~Game();
	void refresh();
	void keyPressed(char code);

	Tank * playerTank;

private:
	bool checkCollision(SceneObject * o1, SceneObject * o2);
	std::list<SceneObject*> obstacles;
	std::list<Tank*>	tanks;
	std::list<Missle*> missles;
	std::list<ComputerOpponent*> opponents;
	
	GLuint lastUpdate;
	Camera * camera;
	Environment * environment;

};