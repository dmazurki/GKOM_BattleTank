//
// Created by damian on 01.01.16.
//

#include "../headers/Assets.h"
#include "../../SOIL.h"
#include <iostream>

Assets& Assets::getAssets()
{
    static Assets assets;
    return assets;
}

Assets::Assets()
{
    std::cout << "Loading ground texture...\n";
    grassTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/grass.jpg",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (grassTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }
}
