#pragma once
#include "Vector3D.h"

class SceneObject
{
public:
	SceneObject();
	Vector3D position;
	Vector3D angle;

	void displayWired(bool wired_);
	bool isWired();

private:
	bool wired;

};