#include "LoadManagerCreator.h"

LoadManager &LoadManagerCreator::getManager() {
    static auto manager = std::make_unique<LoadManager>();
    return *manager;
}
