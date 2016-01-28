#pragma once
#include <list>
#include "../Model/SceneObject.h"
#include "../Model/Tank.h"
#include "../Model/Missle.h"
#include "../Model/Camera.h"
#include "../Model/Environment.h"
#include "../Logic/ComputerOpponent.h"

class Game
{
public:
	static const int UPS = 30;
	static const int MILLISECONDS_INTERSPACE = 1000 / UPS;
	static const GLfloat size;


	Game();
	~Game();
	void refresh();
	void restart();
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