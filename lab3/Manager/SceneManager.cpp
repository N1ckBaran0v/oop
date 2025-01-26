#include "SceneManager.h"
#include "../ManagerVisitor/ManagerVisitor.h"

void SceneManager::accept(ManagerVisitor &visitor) {
    visitor.visit(*this);
}

void SceneManager::setScene(std::shared_ptr<Scene> scene) {
    this->scene = scene;
}

std::shared_ptr<Scene> SceneManager::getScene() {
    return scene;
}
