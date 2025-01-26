#include "RemoveFromCompositeCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"

RemoveFromCompositeCommand::RemoveFromCompositeCommand(
    const std::string &composite, const std::string &object)
    : composite(composite), object(object) {}

void RemoveFromCompositeCommand::execute() {
    auto &manager = SceneManagerCreator::getManager();
    auto scene = manager.getScene();
    scene->get(composite)->remove(scene->get(object));
}
