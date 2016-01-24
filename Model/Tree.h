
#ifndef GKOM_BATTLETANK_TREE_H
#define GKOM_BATTLETANK_TREE_H

#include "SceneObject.h"

class Tree : public SceneObject
{
public:
    static const GLfloat MIN_TREE_HEIGHT;
    static const GLfloat MAX_TREE_HEIGHT;
    static const GLfloat MIN_TREE_RADIUS;
    static const GLfloat MAX_TREE_RADIUS;
    static const GLfloat MIN_TREE_CROWN_RADIUS;
    static const GLfloat MAX_TREE_CROWN_RADIUS;

    Tree(const Vector3D & position);

    void draw();

private:
    GLUquadricObj *treeQuadric;

    GLfloat treeHeight;
    GLfloat treeRadius;
    GLfloat treeCrownRadius;

    GLuint woodTexture;
    GLuint leavesTexture;


};

#endif //GKOM_BATTLETANK_TREE_H
