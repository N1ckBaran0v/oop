#include "DrawSceneCommand.h"
#include "../ManagerCreator/DrawManagerCreator.h"

DrawSceneCommand::DrawSceneCommand(const std::string &camera,
                                   std::shared_ptr<WindowAdapter> adapter)
    : adapter(adapter), camera(camera) {}

void DrawSceneCommand::execute() {
    auto &manager = DrawManagerCreator::getManager();
    manager.draw(camera, adapter);
}
