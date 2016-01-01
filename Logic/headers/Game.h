#pragma once
#include <vector>
#include <list>
#include "../../Model/headers/SceneObject.h"
#include "../../Model/headers/Tank.h"
#include "../../Model/headers/Missle.h"
#include "../../Model/headers/Camera.h"
#include "../../Model/headers/Environment.h"

class Game
{
public:
	static const int UPS = 30;
	static const int MILLISECONDS_INTERSPACE = 1000 / UPS;

	Game();
	~Game();
	void refresh();
	void keyPressed(char code);

    Tank * getPlayerTank() { return playerTank; }
	Tank * playerTank;

private:
	bool checkCollision(SceneObject * o1, SceneObject * o2);
	std::vector<SceneObject*> obstacles;
	std::vector<Tank*>	tanks;
	std::list<Missle*> missles;
	
	GLuint lastUpdate;
	Camera * camera;
	Environment * environment;

};