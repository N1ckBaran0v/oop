#include "ScaleCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"
#include "../ManagerCreator/TransformManagerCreator.h"

ScaleCommand::ScaleCommand(const std::string &object, double cx, double cy,
                             double cz)
    : object(object), cx(cx), cy(cy), cz(cz) {}

void ScaleCommand::execute() {
    auto &transformManager = TransformManagerCreator::getManager();
    auto &sceneManager = SceneManagerCreator::getManager();
    auto scene = sceneManager.getScene();
    auto ptr = scene->get(object);
    ptr->transform(transformManager.scale(cx, cy, cz));
}
