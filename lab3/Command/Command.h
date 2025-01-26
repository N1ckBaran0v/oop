#ifndef __COMMAND_H__
#define __COMMAND_H__

class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif // __COMMAND_H__
