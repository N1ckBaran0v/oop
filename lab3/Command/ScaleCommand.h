#ifndef __SCALE_COMMAND_H__
#define __SCALE_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class ScaleCommand : public SceneObjectCommand {
public:
    ScaleCommand() = delete;
    ScaleCommand(const std::string &, double, double, double);

    void execute() override;

private:
    double cx, cy, cz;
    std::string object;
};

#endif // __SCALE_COMMAND_H__
