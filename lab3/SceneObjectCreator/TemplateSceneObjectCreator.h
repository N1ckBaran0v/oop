#ifndef __TEMPLATE_SCENE_OBJECT_CREATOR_H__
#define __TEMPLATE_SCENE_OBJECT_CREATOR_H__

#include "SceneObjectCreator.h"
#include "../Concepts/Implementation.h"

template <Implementation<SceneObject> Impl>
class TemplateSceneObjectCreator : public SceneObjectCreator {
public:
    std::shared_ptr<SceneObject> createObject() override;
};


template<Implementation<SceneObject> Impl>
std::shared_ptr<SceneObject> TemplateSceneObjectCreator<Impl>::createObject() {
    return std::make_shared<Impl>();
}

#endif // __TEMPLATE_SCENE_OBJECT_CREATOR_H__
