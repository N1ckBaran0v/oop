#ifndef __SCENE_OBJECT_CREATOR_H__
#define __SCENE_OBJECT_CREATOR_H__

#include "../SceneObject/SceneObject.h"

class SceneObjectCreator {
public:
    virtual ~SceneObjectCreator() = default;

    virtual std::shared_ptr<SceneObject> createObject() = 0;
};

#endif // __SCENE_OBJECT_CREATOR_H__
