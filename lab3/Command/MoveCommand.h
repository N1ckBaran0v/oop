#ifndef __MOVE_COMMAND_H__
#define __MOVE_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class MoveCommand : public SceneObjectCommand {
public:
    MoveCommand() = delete;
    MoveCommand(const std::string &, double, double, double);

    void execute() override;

private:
    double dx, dy, dz;
    std::string object;
};

#endif // __MOVE_COMMAND_H__
