#include "DrawManagerCreator.h"

DrawManager &DrawManagerCreator::getManager() {
    static auto manager = std::make_unique<DrawManager>();
    return *manager;
}
