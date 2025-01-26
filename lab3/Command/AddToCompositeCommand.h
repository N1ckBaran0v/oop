#ifndef __ADD_TO_COMPOSITE_COMMAND_H__
#define __ADD_TO_COMPOSITE_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class AddToCompositeCommand : public SceneObjectCommand {
public:
    AddToCompositeCommand() = delete;
    AddToCompositeCommand(const std::string &, const std::string &);

    void execute() override;

private:
    std::string composite, object;
};

#endif // __ADD_TO_COMPOSITE_COMMAND_H__
