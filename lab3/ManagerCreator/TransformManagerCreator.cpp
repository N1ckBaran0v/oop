#include "TransformManagerCreator.h"

TransformManager &TransformManagerCreator::getManager() {
    static auto manager = std::make_unique<TransformManager>();
    return *manager;
}
