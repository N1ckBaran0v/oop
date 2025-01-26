#ifndef __CLEAR_SCENE_COMMAND_H__
#define __CLEAR_SCENE_COMMAND_H__

#include "SceneCommand.h"

class ClearSceneCommand : public SceneCommand {
public:
    void execute() override;
};

#endif // __CLEAR_SCENE_COMMAND_H__
