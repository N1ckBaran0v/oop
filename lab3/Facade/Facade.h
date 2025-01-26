#ifndef __FACADE_H__
#define __FACADE_H__

#include <memory>

#include "../Command/Command.h"

class Facade {
public:
    Facade() = delete;

    static void execute(std::shared_ptr<Command> command)  {
        command->execute();
    }
};

#endif // __FACADE_H__
