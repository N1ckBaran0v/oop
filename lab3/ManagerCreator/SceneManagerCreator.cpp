#include "SceneManagerCreator.h"

SceneManager &SceneManagerCreator::getManager() {
    static auto manager = std::make_unique<SceneManager>();
    return *manager;
}
