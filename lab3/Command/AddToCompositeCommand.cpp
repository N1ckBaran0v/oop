#include "AddToCompositeCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"

AddToCompositeCommand::AddToCompositeCommand(const std::string &composite,
                                             const std::string &object)
    : composite(composite), object(object) {}

void AddToCompositeCommand::execute() {
    auto &manager = SceneManagerCreator::getManager();
    auto scene = manager.getScene();
    scene->get(composite)->add(scene->get(object));
}
