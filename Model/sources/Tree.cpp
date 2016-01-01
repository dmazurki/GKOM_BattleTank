//
// Created by damian on 01.01.16.
//

#include "../headers/Tree.h"
#include "../../Assets/headers/Assets.h"
#include <random>
#include <chrono>

Tree::Tree(const Vector3D &position_)
{
    this->position = position_;

    treeQuadric = gluNewQuadric();
    gluQuadricNormals(treeQuadric, GLU_SMOOTH);
    gluQuadricTexture(treeQuadric, GL_TRUE);

    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::uniform_real_distribution<float_t> distribution(MIN_TREE_HEIGHT, MAX_TREE_HEIGHT);
    treeHeight = distribution(generator);
    distribution = std::uniform_real_distribution<float_t>(MIN_TREE_RADIUS, MAX_TREE_RADIUS);
    treeRadius = distribution(generator);
    distribution = std::uniform_real_distribution<float_t>(MIN_TREE_CROWN_RADIUS, MAX_TREE_CROWN_RADIUS);
    treeCrownRadius = distribution(generator);

    collisionRadius = treeRadius;

    woodTexture = Assets::getAssets().woodTexture;
    leavesTexture = Assets::getAssets().leavesTexture;



}

void Tree::draw() {

    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D, woodTexture);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    gluCylinder(treeQuadric, treeRadius,treeRadius*0.4, treeHeight, 8,8);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, leavesTexture);

    glMatrixMode (GL_TEXTURE);
    glPushMatrix();
    glLoadIdentity ();
    glScalef (4, 4, 4);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,treeHeight,0);
    gluSphere(treeQuadric, treeCrownRadius,6,6);
    glPopMatrix();

    glMatrixMode (GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

const GLfloat Tree::MIN_TREE_HEIGHT = 6;
const GLfloat Tree::MAX_TREE_HEIGHT = 9;
const GLfloat Tree::MIN_TREE_RADIUS = 0.5;
const GLfloat Tree::MAX_TREE_RADIUS = 1.5;
const GLfloat Tree::MIN_TREE_CROWN_RADIUS = 3;
const GLfloat Tree::MAX_TREE_CROWN_RADIUS = 4.5;