#include "Scene.h"

bool Scene::add(const std::string &name, std::shared_ptr<SceneObject> obj) {
    auto answer = objects[name] == nullptr;
    if (answer) {
        objects[name] = obj;
    }
    return answer;
}

std::shared_ptr<SceneObject> Scene::get(const std::string &name) {
    return objects[name];
}

bool Scene::remove(const std::string &name) {
    auto answer = objects[name] != nullptr;
    if (answer) {
        objects.erase(objects.find(name));
    }
    return answer;
}

std::map<std::string, std::shared_ptr<SceneObject>>::iterator Scene::begin() {
    return objects.begin();
}

std::map<std::string, std::shared_ptr<SceneObject>>::iterator Scene::end() {
    return objects.end();
}
