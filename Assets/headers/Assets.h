//
// Created by damian on 01.01.16.
//

#ifndef GKOM_BATTLETANK_ASSETS_H
#define GKOM_BATTLETANK_ASSETS_H

#include <GL/gl.h>

class Assets
{
public:
    static Assets & getAssets();

    GLuint grassTexture;
    GLuint woodTexture;
    GLuint leafsTexture;
private:
    Assets();

};
#endif //GKOM_BATTLETANK_ASSETS_H
