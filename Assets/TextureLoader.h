//
// Created by damian on 24.01.16.
//

#ifndef GKOM_BATTLETANK_TEXTURELOADER_H
#define GKOM_BATTLETANK_TEXTURELOADER_H


#include<stdio.h>
#ifdef __linux__
#include "GL/glut.h"

#define BYTE  unsigned char
#define DWORD  unsigned int
#define LONG  int
#define UINT  unsigned int
#define WORD  unsigned short int
#define LPSTR  char*

#pragma pack(1)
typedef struct tagBITMAPFILEHEADER {
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
#pragma pack()

#pragma pack(1)
typedef struct tagBITMAPINFOHEADER{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack()

#elif _WIN32
#include <windows.h>
#include "glut.h"
#endif

const int BITMAP_ID = 0x4D42;

// based on www.opengl-tutorial.org/beginners-tutorials
// for creating GL Texture used http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
// for using Windows structs on Windows used : http://cboard.cprogramming.com/cplusplus-programming/91400-bmp-loading-structs.html
// and http://stackoverflow.com/questions/3318410/pragma-pack-effect
class TextureLoader
{
public:
    TextureLoader();
    ~TextureLoader();
    bool load(char *name);
    int getImageWidth() const;
    int getImageHeight() const;
    unsigned int ID;
    unsigned char *image;
private:
    int imageWidth;
    int imageHeight;
};


#endif //GKOM_BATTLETANK_TEXTURELOADER_H
