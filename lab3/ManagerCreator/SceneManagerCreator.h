#ifndef __SCENE_MANAGER_CREATOR_H__
#define __SCENE_MANAGER_CREATOR_H__

#include <memory>

#include "../Manager/SceneManager.h"

class SceneManagerCreator {
public:
    SceneManagerCreator() = delete;

    static SceneManager &getManager();
};

#endif // __SCENE_MANAGER_CREATOR_H__
