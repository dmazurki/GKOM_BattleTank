#include "../headers/Game.h"
#include "../../Model/headers/Tree.h"
#include <cmath>

Game::Game()
{
	playerTank = new Tank();
	tanks.push_back(playerTank);

	camera = new Camera(playerTank, 9);
	environment = new Environment(100);

	obstacles.push_back(new Tree(Vector3D(20,0,0)));
	obstacles.push_back(new Tree(Vector3D(6,0,7)));
	obstacles.push_back(new Tree(Vector3D(7,0,-14)));



	lastUpdate = 0;
}
Game::~Game() 
{

	for (auto obstacle : obstacles)
	{
		delete obstacle;
	}
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

		for(auto obstacle : obstacles)
		{
			for( auto tank : tanks)
			{
				if(checkCollision(tank,obstacle))
					tank->bounce();
			}
		}

		camera->updatePosition();

		lastUpdate = glutGet(GLUT_ELAPSED_TIME);
	}

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	camera->refresh();

	glMatrixMode(GL_MODELVIEW);


	

	for (auto tank : tanks)
		tank->draw();
	for (auto missle : missles)
		missle->draw();
	for( auto obstacle : obstacles)
		obstacle->draw();
	environment->draw();

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

bool Game::checkCollision(SceneObject * o1, SceneObject * o2)
{
	GLfloat distanceX = std::abs(o1->position.x - o2->position.x);
	GLfloat distanceZ = std::abs(o1->position.z - o2->position.z);

	GLfloat distance = std::sqrt( distanceX*distanceX + distanceZ*distanceZ);

	return distance < (o1->collisionRadius + o2->collisionRadius);
}