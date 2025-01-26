#ifndef __FRAME_MODEL_BASE_CREATOR_H__
#define __FRAME_MODEL_BASE_CREATOR_H__

#include "FrameModelBuilder.h"
#include "SceneObjectCreator.h"

class FrameModelBaseCreator : public SceneObjectCreator {
public:
    virtual ~FrameModelBaseCreator() = default;

    std::shared_ptr<SceneObject> createObject() override;

protected:
    std::shared_ptr<FrameModelBuilder> builder;
};

#endif // __FRAME_MODEL_BASE_CREATOR_H__
