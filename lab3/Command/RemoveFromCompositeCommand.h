#ifndef __REMOVE_FROM_COMPOSITE_COMMAND_H__
#define __REMOVE_FROM_COMPOSITE_COMMAND_H__

#include <string>

#include "SceneObjectCommand.h"

class RemoveFromCompositeCommand : public SceneObjectCommand {
public:
    RemoveFromCompositeCommand() = delete;
    RemoveFromCompositeCommand(const std::string &, const std::string &);

    void execute() override;

private:
    std::string composite, object;
};

#endif // __REMOVE_FROM_COMPOSITE_COMMAND_H__
