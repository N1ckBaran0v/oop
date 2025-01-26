#ifndef __ROTATE_COMMAND_H__
#define __ROTATE_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class RotateCommand : public SceneObjectCommand {
public:
    RotateCommand() = delete;
    RotateCommand(const std::string &, double, double, double);

    void execute() override;

private:
    double ox, oy, oz;
    std::string object;
};

#endif // __ROTATE_COMMAND_H__
