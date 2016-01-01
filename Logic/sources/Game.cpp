#include "../headers/Game.h"
Game::Game()
{
	playerTank = new Tank();
	tanks.push_back(playerTank);

	camera = new Camera(playerTank, 4);
	environment = new Environment(100);

	lastUpdate = 0;
}
Game::~Game() 
{
	for (auto tank : tanks)
	{
		delete tank;
	}
	for (auto missle : missles)
		delete missle;

	delete camera;
	delete environment;
}
void Game::refresh() 
{
	if (glutGet(GLUT_ELAPSED_TIME) - lastUpdate > MILLISECONDS_INTERSPACE)
	{
		for (auto tank : tanks)
			tank->update();
		for (auto missle : missles)
		{
			missle->update();
		}
		missles.remove_if([](Missle * x)->bool
		{	if (x->position.y + 10 < 0)
			{
				delete x;
				return true;
			}
			return false;
		});

		if (playerTank->position.x > 30)
			playerTank->bounce();

		camera->updatePosition();

		lastUpdate = glutGet(GLUT_ELAPSED_TIME);
	}

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	camera->refresh();

	glMatrixMode(GL_MODELVIEW);
	environment->refresh();
	

	

	for (auto tank : tanks)
		tank->draw();
	for (auto missle : missles)
		missle->draw();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
}

void Game::keyPressed(char code)
{
	switch (code)
	{
	case 'w': playerTank->move(1); break;
	case 's': playerTank->move(-1); break;
	case 'a': playerTank->turn(-1);  break;
	case 'd': playerTank->turn(1); break;
	case 'f': 
		missles.push_back(playerTank->shoot()); 
		break;
	}

}