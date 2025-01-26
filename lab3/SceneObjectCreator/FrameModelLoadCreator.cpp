#include <fstream>

#include "FrameModelLoadCreator.h"
#include "FrameModelLoader.h"

FrameModelLoadCreator::FrameModelLoadCreator(const std::string &filename) : filename(filename) {}

std::shared_ptr<SceneObject> FrameModelLoadCreator::createObject() {
    std::ifstream input;
    input.open(filename);
    if (input.is_open()) {
        builder = std::make_shared<FrameModelLoader>(input);
        auto result = FrameModelBaseCreator::createObject();
        input.close();
        return result;
    }
    return nullptr;
}
