#include "../headers/SceneObject.h"
SceneObject::SceneObject() {wired = false; }
void   SceneObject::displayWired(bool wired_) { wired = wired_; }
bool SceneObject::isWired() { return wired; }
