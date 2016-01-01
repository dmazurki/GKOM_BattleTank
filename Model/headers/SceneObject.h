#pragma once
#include "Vector3D.h"

class SceneObject
{
public:
	SceneObject();
	Vector3D position;
	Vector3D angle;
	GLfloat collisionRadius;

	void displayWired(bool wired_);
	bool isWired();
	virtual void draw() = 0;

private:
	bool wired;

};