#include "RotateCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"
#include "../ManagerCreator/TransformManagerCreator.h"

RotateCommand::RotateCommand(const std::string &object, double ox, double oy,
                             double oz)
    : object(object), ox(ox), oy(oy), oz(oz) {}

void RotateCommand::execute() {
    auto &transformManager = TransformManagerCreator::getManager();
    auto &sceneManager = SceneManagerCreator::getManager();
    auto scene = sceneManager.getScene();
    auto ptr = scene->get(object);
    ptr->transform(transformManager.rotate(ox, oy, oz));
}
