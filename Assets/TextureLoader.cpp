//
// Created by damian on 24.01.16.
//

#include "TextureLoader.h"

TextureLoader::TextureLoader() : image(0), imageWidth(0), imageHeight(0) {}

TextureLoader::~TextureLoader()
{
    if (image)
    {
        delete[] image;
        image = 0;
    }
}

bool TextureLoader::load(char *file)
{
    image = nullptr;
    FILE *pFile = NULL;
    BITMAPINFOHEADER bitmapInfoHeader;
    BITMAPFILEHEADER header;
    unsigned char textureColors = 0;

    pFile = fopen(file, "rb");  //open file
    if(!pFile)
    {
        return false;
    }

    fread(&header, sizeof(BITMAPFILEHEADER), 1, pFile);
    if(header.bfType != BITMAP_ID)
    {
        fclose(pFile);
        return false;
    }

    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, pFile);  // parse header for size
    imageWidth = bitmapInfoHeader.biWidth;
    imageHeight = bitmapInfoHeader.biHeight;

    if(bitmapInfoHeader.biSizeImage == 0)    // Make sure we read a size out of it.
    {
        bitmapInfoHeader.biSizeImage = bitmapInfoHeader.biWidth * bitmapInfoHeader.biHeight * 3;
    }

    fseek(pFile, header.bfOffBits, SEEK_SET);   // set to the factual beginning

    if(image!= nullptr)
    {
        delete [] image;
        image = nullptr;
    }

    image = new unsigned char[bitmapInfoHeader.biSizeImage];
    if(!image)
    {
        delete[] image;
        fclose(pFile);
        return false;
    }

    fread(image, 1, bitmapInfoHeader.biSizeImage, pFile);  // read image


    for(int index = 0; index < (int)bitmapInfoHeader.biSizeImage; index+=3) // to RGB
    {
        textureColors = image[index];
        image[index] = image[index + 2];
        image[index + 2] = textureColors;
    }
    fclose(pFile);

    // Create one OpenGL texture

    glGenTextures(1, &ID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, ID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, getImageWidth(), getImageHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    return true;


}

int TextureLoader::getImageWidth() const
{
    return imageWidth;
}

int TextureLoader::getImageHeight() const
{
    return imageHeight;
}