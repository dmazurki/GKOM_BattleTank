//
// Created by damian on 01.01.16.
//

#ifndef GKOM_BATTLETANK_COMPUTEROPPONENT_H
#define GKOM_BATTLETANK_COMPUTEROPPONENT_H

#include "../Model/Tank.h"
#include <list>
#include <random>

class ComputerOpponent
{
public:
    static const int MIN_SHOOT_INTERVAL;
    static const int MAX_SHOOT_INTERVAL;
    static const int MIN_WANDER_TIME;
    static const int MAX_WANDER_TIME;
    static const int MIN_WANDER_INTERVAL;
    static const int MAX_WANDER_INTERVAL;


    ComputerOpponent(Tank *);

    void action(const std::list<Tank*> & players, std::list<Missle*> & missles);

private:
    Tank * self;

    bool chase;
    Vector3D objective;

    int shootInteval;
    int wanderTime;
    int wanderInterval;

    int currentShootInteval;
    int currentWanderTime;
    int currentWanderInterval;


    std::default_random_engine generator;


};

#endif //GKOM_BATTLETANK_COMPUTEROPPONENT_H
