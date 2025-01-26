#include "RemoveObjectCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"

RemoveObjectCommand::RemoveObjectCommand(const std::string &name) : name(name) {}

void RemoveObjectCommand::execute() {
    auto &manager = SceneManagerCreator::getManager();
    auto scene = manager.getScene();
    scene->remove(name);
}
