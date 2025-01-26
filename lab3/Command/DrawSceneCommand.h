#ifndef __DRAW_SCENE_COMMAND_H__
#define __DRAW_SCENE_COMMAND_H__

#include <memory>
#include <string>

#include "../WindowAdapter/WindowAdapter.h"
#include "SceneCommand.h"

class DrawSceneCommand : public SceneCommand {
public:
    DrawSceneCommand() = delete;

    void execute() override;

protected:
    explicit DrawSceneCommand(const std::string &, std::shared_ptr<WindowAdapter>);

private:
    std::shared_ptr<WindowAdapter> adapter;
    std::string camera;
};

#endif // __DRAW_SCENE_COMMAND_H__
