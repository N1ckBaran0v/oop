#ifndef __REMOVE_OBJECT_COMMAND_H__
#define __REMOVE_OBJECT_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class RemoveObjectCommand : public SceneObjectCommand
{
public:
    RemoveObjectCommand() = delete;
    RemoveObjectCommand(const std::string &);

    void execute() override;

private:
    std::string name;
};

#endif // __REMOVE_OBJECT_COMMAND_H__
