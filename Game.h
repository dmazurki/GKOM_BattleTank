#pragma once
#include <vector>
#include <list>
#include "SceneObject.h"
#include "Tank.h"
#include "Missle.h"
#include "Camera.h"
#include "Environment.h"

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
	std::vector<SceneObject*> obstacles;
	std::vector<Tank*>	tanks;
	std::list<Missle*> missles;
	
	GLuint lastUpdate;
	Camera * camera;
	Environment * environment;

};