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
    groundTexture = SOIL_load_OGL_texture
            (


                    "../Assets/resources/ground.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (groundTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading wall texture...\n";
    wallTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/wall.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (wallTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading wood texture...\n";
    woodTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/wood.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (woodTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading sky texture...\n";
    skyTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/sky.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (skyTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading leaves texture...\n";
    leavesTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/leaves.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (leavesTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading panzer gun and tower  texture...\n";
    panzerTowerGunTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/panzer_tower_gun.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (panzerTowerGunTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading panzer box  texture...\n";
    panzerBoxTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/panzer_box.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS |  SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (panzerBoxTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading panzer caterpillar  texture...\n";
    panzerCaterpillarTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/caterpillar.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS |  SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (panzerCaterpillarTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

    std::cout << "Loading panzer missle  texture...\n";
    missleTexture = SOIL_load_OGL_texture
            (
                    "../Assets/resources/missle.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS |  SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );
    if (missleTexture == 0)
    {
        std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
    }

}
