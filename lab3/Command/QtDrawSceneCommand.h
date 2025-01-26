#ifndef __QT_DRAW_SCENE_COMMAND_H__
#define __QT_DRAW_SCENE_COMMAND_H__

#include <QPainter>

#include "DrawSceneCommand.h"

class QtDrawSceneCommand : public DrawSceneCommand {
public:
    QtDrawSceneCommand() = delete;
    QtDrawSceneCommand(const std::string &, QPainter &, int, int);
};

#endif // __QT_DRAW_SCENE_COMMAND_H__
