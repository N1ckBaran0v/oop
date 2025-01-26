#ifndef __ADD_OBJECT_COMMAND_H__
#define __ADD_OBJECT_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class AddObjectCommand : public SceneObjectCommand {
public:
    AddObjectCommand() = delete;
    AddObjectCommand(const std::string &, const std::string &);

    void execute() override;

private:
    std::string type, name;
};

#endif // __ADD_OBJECT_COMMAND_H__
