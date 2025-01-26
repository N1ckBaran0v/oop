#include "FrameModelBaseCreator.h"
#include "../SceneObject/FrameModel.h"

std::shared_ptr<SceneObject> FrameModelBaseCreator::createObject() {
    auto center = builder->createCenter();
    auto dots = builder->createDots();
    auto segments = builder->createSegments();
    return std::make_shared<FrameModel>(center, dots, segments);
}
