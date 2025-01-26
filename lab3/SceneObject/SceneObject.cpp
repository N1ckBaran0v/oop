#include "SceneObject.h"

bool SceneObject::add(std::shared_ptr<SceneObject> obj) { return false; }

bool SceneObject::remove(std::shared_ptr<SceneObject> obj) { return false; }

bool SceneObject::isComposite() const { return false; }

const Dot &SceneObject::getCenter() const { return center; }

void SceneObject::setCenter(const Dot &center) { this->center = center; }
