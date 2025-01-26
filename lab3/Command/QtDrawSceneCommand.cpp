#include "QtDrawSceneCommand.h"
#include "../WindowAdapter/QtAdapter.h"

QtDrawSceneCommand::QtDrawSceneCommand(const std::string &camera,
                                       QPainter &painter, int x, int y)
    : DrawSceneCommand(camera, std::make_shared<QtAdapter>(painter, x, y)) {}
