#include "DrawManager.h"
#include "../ManagerVisitor/ManagerVisitor.h"
#include "../SceneVisitor/DrawVisitor.h"
#include "../SceneObject/Camera.h"
#include "../ManagerCreator/SceneManagerCreator.h"

void DrawManager::accept(ManagerVisitor &visitor) { visitor.visit(*this); }

void DrawManager::draw(const std::string &camera,
                       std::shared_ptr<WindowAdapter> adapter) {
    auto &sceneManager = SceneManagerCreator::getManager();
    auto scene = sceneManager.getScene();
    std::shared_ptr<SceneVisitor> visitor =
        std::make_shared<DrawVisitor>(*(dynamic_cast<Camera*>(scene->get(camera).get())), adapter);
    for (auto elem : *scene) {
        auto obj = elem.second;
        obj->accept(*visitor);
    }
}
