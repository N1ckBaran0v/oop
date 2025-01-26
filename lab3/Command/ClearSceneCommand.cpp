#include "ClearSceneCommand.h"
#include "../ManagerCreator/SceneManagerCreator.h"

void ClearSceneCommand::execute() {
    auto &manager = SceneManagerCreator::getManager();
    manager.setScene(std::make_shared<Scene>());
}
