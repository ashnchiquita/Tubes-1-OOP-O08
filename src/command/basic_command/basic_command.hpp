#ifndef BASIC_COMMAND_H
#define BASIC_COMMAND_H

#include "../command.hpp"

class BasicCommand : public Command {
    public:
        BasicCommand(Game*);
        virtual void execute() = 0;
        virtual ~BasicCommand();
};

#endif