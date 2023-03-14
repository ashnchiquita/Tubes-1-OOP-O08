#ifndef BASIC_COMMAND_H
#define BASIC_COMMAND_H

#include "command.hpp"

class BasicCommand : public Command {
    public:
        BasicCommand(Game*);
        virtual void execute() = 0;
};

class Double : public BasicCommand{
    public:
        Double(Game*);
        void execute();
};

class Half : public BasicCommand{
    public:
        Half(Game*);
        void execute();
};

class Next : public BasicCommand{
    public:
        Next(Game*);
        void execute();
};

#endif