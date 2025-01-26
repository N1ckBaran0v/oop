#include "LoadSolution.h"

std::shared_ptr<SceneObjectCreator> LoadSolution::createCreator(const std::string &name){
    return creators[name];
}

bool LoadSolution::registration(const std::string &name, std::shared_ptr<SceneObjectCreator> obj) {
    auto result = obj != nullptr && creators[name] == nullptr;
    if (result) {
        creators[name] = obj;
    }
    return result;
}
