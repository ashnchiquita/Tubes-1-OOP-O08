#ifndef BASIC_COMMAND_H
#define BASIC_COMMAND_H

#include "command.hpp"

class BasicCommand : public Command {
    public:
        BasicCommand(Game*);
        virtual void execute() = 0;
        virtual ~BasicCommand();
};

class Double : public BasicCommand{
    public:
        Double(Game*);
        void execute();
        ~Double();
};

class Half : public BasicCommand{
    public:
        Half(Game*);
        void execute();
        ~Half();
};

class Next : public BasicCommand{
    public:
        Next(Game*);
        void execute();
        ~Next();
};

#endif