#include "Ground.h"
#include <iostream>


Ground::Ground(GLfloat size_) : size(size_)
{
	std::cout << "Loading ground texture...\n";
	this->texture = SOIL_load_OGL_texture
		(
			"Assets/grass.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
	if (0 == this->texture)
	{
		std::cout << "Texture loading error: " << SOIL_last_result() << std::endl;
	}
}
void Ground::refresh()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, texture);


		
			glBegin(GL_QUADS);

			glTexCoord2f(0.0, 0.0); glVertex3f(-size/2, 0.0, -size / 2);
			glTexCoord2f(0.0, 10.0); glVertex3f(-size / 2, 0.0, size / 2);
			glTexCoord2f(10.0, 10.0); glVertex3f(size / 2, 0.0, size / 2);
			glTexCoord2f(10.0, 0.0); glVertex3f(size / 2, 0.0, -size / 2);
			glEnd();


			glPopMatrix();
		
	

	
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}



