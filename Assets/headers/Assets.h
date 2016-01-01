//
// Created by damian on 01.01.16.
//

#ifndef GKOM_BATTLETANK_ASSETS_H
#define GKOM_BATTLETANK_ASSETS_H

#ifdef __linux__
#include "GL/glut.h"
#elif _WIN32
#include "../../glut.h"
#endif

class Assets
{
public:
    static Assets & getAssets();

    GLuint groundTexture;
    GLuint skyTexture;
    GLuint woodTexture;
    GLuint leavesTexture;

    GLuint panzerTowerGunTexture;
    GLuint panzerBoxTexture;
    GLuint panzerCaterpillarTexture;

    GLuint missleTexture;

private:
    Assets();

};
#endif //GKOM_BATTLETANK_ASSETS_H
