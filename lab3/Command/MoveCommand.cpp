#include "MoveCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"
#include "../ManagerCreator/TransformManagerCreator.h"

MoveCommand::MoveCommand(const std::string &object, double dx, double dy,
                         double dz)
    : object(object), dx(dx), dy(dy), dz(dz) {}

void MoveCommand::execute() {
    auto &transformManager = TransformManagerCreator::getManager();
    auto &sceneManager = SceneManagerCreator::getManager();
    auto scene = sceneManager.getScene();
    auto ptr = scene->get(object);
    ptr->transform(transformManager.move(dx, dy, dz));
}
