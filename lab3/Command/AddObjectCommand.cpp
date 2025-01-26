#include "AddObjectCommand.h"
#include "../ManagerCreator/LoadManagerCreator.h"
#include "../ManagerCreator/SceneManagerCreator.h"

AddObjectCommand::AddObjectCommand(const std::string &type,
                                   const std::string &name)
    : type(type), name(name) {}

void AddObjectCommand::execute() {
    auto &sceneManager = SceneManagerCreator::getManager();
    auto &loadManager = LoadManagerCreator::getManager();
    auto scene = sceneManager.getScene();
    scene->add(name, loadManager.loadModel(type));
}
