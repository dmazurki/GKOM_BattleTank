#include "Game.h"
#include "../Model/Tree.h"
#include <cmath>
#include <iostream>

Game::Game()
{
	playerTank = new Tank();
	tanks.push_back(playerTank);


	Tank * opponent1 = new Tank(Vector3D(4,0,0));
	tanks.push_back(opponent1);
	opponents.push_back(new ComputerOpponent(opponent1));




	camera = new Camera(playerTank, 9);

	environment = new Environment(size);


	long seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);


	for(GLfloat x = -size*0.7; x<size*0.7; x+=9)
		for(GLfloat z = -size*0.7; z<size*0.7; z+=9)
		{
			int randomVal = std::uniform_int_distribution<int>(0, 100)(generator);
			if(randomVal>=0 && randomVal<10)
				obstacles.push_back(new Tree(Vector3D(x,0,z)));

		}









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

	for (auto opponent : opponents)
		delete opponent;

	delete camera;
	delete environment;
}
void Game::refresh() 
{
	if (glutGet(GLUT_ELAPSED_TIME) - lastUpdate > MILLISECONDS_INTERSPACE)
	{
		for (auto tank : tanks) {
			tank->update();
		}


		for(auto opponent : opponents)
			opponent->action(tanks,missles);

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

		for( auto tank : tanks)
		{
			if(std::sqrt(tank->position.x*tank->position.x + tank->position.z*tank->position.z)>Game::size)
				tank->bounce(nullptr);

			for(auto obstacle : obstacles)
			{
				if(checkCollision(tank,obstacle))
					tank->bounce(obstacle);
			}
		}


		for(auto tank1 : tanks)
		{
			for( auto tank2 : tanks)
			{
				if(tank1!=tank2 && checkCollision(tank1,tank2)) {
					tank1->bounce(tank2);
					tank2->bounce(tank1);
				}
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
		case 'c': camera->changeSetting(); break;
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

const GLfloat Game::size = 60;
