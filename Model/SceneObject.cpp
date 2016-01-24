#include "SceneObject.h"
SceneObject::SceneObject() {wired = false; collisionRadius = 0;}
void   SceneObject::displayWired(bool wired_) { wired = wired_; }
bool SceneObject::isWired() { return wired; }
