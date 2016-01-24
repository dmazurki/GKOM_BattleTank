//
// Created by damian on 01.01.16.
//

#include "../headers/Assets.h"
#include "../../SOIL.h"
#include "../headers/TextureLoader.h"
#include <iostream>

Assets& Assets::getAssets()
{
    static Assets assets;
    return assets;
}

Assets::Assets()
{
    auto tl  = TextureLoader();

    tl.load("../Assets/resources/ground.bmp");
    groundTexture = tl.ID;
    std::cout << "Loading ground texture...\n";


    std::cout << "Loading wall texture...\n";
    tl.load("../Assets/resources/wall.bmp");
    wallTexture = tl.ID;

    std::cout << "Loading wood texture...\n";
    tl.load("../Assets/resources/wood.bmp");
    woodTexture = tl.ID;


    std::cout << "Loading sky texture...\n";
    tl.load("../Assets/resources/sky.bmp");
    skyTexture = tl.ID;


    std::cout << "Loading leaves texture...\n";
    tl.load("../Assets/resources/leaves.bmp");
    leavesTexture = tl.ID;


    std::cout << "Loading panzer gun and tower  texture...\n";
    tl.load("../Assets/resources/panzer_tower_gun.bmp");
    panzerTowerGunTexture = tl.ID;


    std::cout << "Loading panzer box  texture...\n";
    tl.load("../Assets/resources/panzer_box.bmp");
    panzerBoxTexture = tl.ID;

    std::cout << "Loading panzer caterpillar  texture...\n";
    tl.load("../Assets/resources/caterpillar.bmp");
    panzerCaterpillarTexture = tl.ID;

    std::cout << "Loading panzer missle  texture...\n";
    tl.load("../Assets/resources/missle.bmp");

    missleTexture = tl.ID;

}
