#include "ComputerOpponent.h"
#include "../Logic/Game.h"
#include <cmath>
#include <iostream>


ComputerOpponent::ComputerOpponent(Tank * self_)
{
    self = self_;

    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);


    shootInteval = std::uniform_int_distribution<int>(MIN_SHOOT_INTERVAL, MAX_SHOOT_INTERVAL)(generator);
    wanderTime = std::uniform_int_distribution<int>(MIN_WANDER_TIME, MAX_WANDER_TIME)(generator);
    wanderInterval = std::uniform_int_distribution<int>(MIN_WANDER_INTERVAL, MAX_WANDER_INTERVAL)(generator);

    chase = true;
}

void ComputerOpponent::action(const std::list<Tank*> & opponents,  std::list<Missle*> & missles)
{
    self->move(1);

    if((chase == false))
    {
        currentWanderTime++;
        if(currentWanderTime>wanderTime)
        {
            chase = true;
            wanderInterval = std::uniform_int_distribution<int>(MIN_WANDER_INTERVAL, MAX_WANDER_INTERVAL)(generator);
            currentWanderInterval = 0;
        }
    }
    if((chase == true && self->getSpeed()<0) || (chase == true && currentWanderInterval  > wanderInterval))
    {
        wanderTime = std::uniform_int_distribution<int>(MIN_WANDER_TIME, MAX_WANDER_TIME)(generator);
        currentWanderTime = 0;
        objective.x =  std::uniform_real_distribution<float_t>(0, Game::size * (sqrtf(2) / 2))(generator);
        objective.y =  std::uniform_real_distribution<float_t>(0, Game::size * (sqrtf(2) / 2))(generator);

        chase = false;
    }
    else
    if(chase == true)
    {
        currentWanderInterval++;

        Tank * toChase = nullptr;
        GLfloat minDistance=10000;

        //Finding opponent to shoot.
        for(Tank * opponent : opponents)
        {
            if(opponent == self)
                continue;

            GLfloat distanceX = self->position.x - opponent->position.x;
            GLfloat distanceZ = self->position.z - opponent->position.z;

            GLfloat distance = std::sqrt(distanceX*distanceX + distanceZ*distanceZ);

            if(distance<minDistance)
            {
                minDistance = distance;
                toChase = opponent;
            }
        }

        objective = toChase->position;
    }

    //Chasing opponent.
    GLfloat differenceX = self->position.x - objective.x;
    GLfloat differenceZ = self->position.z - objective.z;
    GLfloat desiredAngle = 0;

    if(differenceX>=0)
        desiredAngle = std::atan(-(differenceZ/differenceX))*(180 / 3.1415);
    else {
        desiredAngle = std::atan(-(differenceZ/differenceX))*(180 / 3.1415);
        desiredAngle+=180;
    }


    desiredAngle+=180;

    while (desiredAngle > 360) desiredAngle -= 360;
    while (desiredAngle < 0) desiredAngle += 360;

    //std::cout<<desiredAngle<<" "<<self->angle.y<<std::endl;


    GLfloat selfAngle = self->angle.y;
    int multiplier;
    if(self->getSpeed()>0)
        multiplier = 1;
    else
        multiplier = -1;

    if(selfAngle+Tank::TURN_DIFFRENTIAL<desiredAngle)
    {
        if(desiredAngle-selfAngle<180)
            self->turn(-1*multiplier);
        else
            self->turn(1*multiplier);

    }
    else
    if(selfAngle-Tank::TURN_DIFFRENTIAL>desiredAngle)
    {
        if(selfAngle - desiredAngle<180)
            self->turn(1*multiplier);
        else
            self->turn(-1*multiplier);
    }

    if(chase==true)
    {
        if(currentShootInteval<shootInteval)
            currentShootInteval++;
        else
        {
            shootInteval = std::uniform_real_distribution<float_t>(MIN_SHOOT_INTERVAL, MAX_SHOOT_INTERVAL)(generator);
            currentShootInteval = 0;
            missles.push_back(self->shoot());
        }
    }

}


const int ComputerOpponent::MIN_SHOOT_INTERVAL = Game::UPS/2;
const int ComputerOpponent::MAX_SHOOT_INTERVAL = Game::UPS*2;
const int ComputerOpponent::MIN_WANDER_TIME = Game::UPS*3;
const int ComputerOpponent::MAX_WANDER_TIME = Game::UPS*6;
const int ComputerOpponent::MIN_WANDER_INTERVAL = Game::UPS*5;
const int ComputerOpponent::MAX_WANDER_INTERVAL = Game::UPS*10;