#ifndef __FRAME_MODEL_LOAD_CREATOR_H__
#define __FRAME_MODEL_LOAD_CREATOR_H__

#include <string>

#include "FrameModelBaseCreator.h"

class FrameModelLoadCreator : public FrameModelBaseCreator
{
public:
    FrameModelLoadCreator() = delete;
    FrameModelLoadCreator(const std::string &);

    std::shared_ptr<SceneObject> createObject() override;

private:
    std::string filename;
};

#endif // __FRAME_MODEL_LOAD_CREATOR_H__
