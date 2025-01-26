#include "LoadManager.h"
#include "../ManagerVisitor/ManagerVisitor.h"
#include "../SceneObject/Camera.h"
#include "../SceneObject/Composite.h"
#include "../SceneObjectCreator/FrameModelLoadCreator.h"
#include "../SceneObjectCreator/TemplateSceneObjectCreator.h"

LoadManager::LoadManager() : loader(std::make_shared<LoadSolution>()) {
    loader->registration("Camera",
                         std::make_shared<TemplateSceneObjectCreator<Camera>>());
    loader->registration("Cube", std::make_shared<FrameModelLoadCreator>(
                                     "../../resources/cube.txt"));
    loader->registration("Pyramide", std::make_shared<FrameModelLoadCreator>(
                                         "../../resources/pyramide.txt"));
    loader->registration(
        "Composite", std::make_shared<TemplateSceneObjectCreator<Composite>>());
}

void LoadManager::accept(ManagerVisitor &visitor) { visitor.visit(*this); }

std::shared_ptr<SceneObject> LoadManager::loadModel(const std::string &name) {
    auto creator = loader->createCreator(name);
    if (creator) {
        return creator->createObject();
    }
    return nullptr;
}
