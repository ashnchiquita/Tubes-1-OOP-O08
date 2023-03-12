#ifndef BASIC_COMMAND_H
#define BASIC_COMMAND_H

#include "command.hpp"

class BasicCommand : public Command {
    public:
        virtual void execute(Game& currGame) = 0;
};

class Double : public BasicCommand{
    public:
        void execute(Game& currGame);
};

class Half : public BasicCommand{
    public:
        void execute(Game& currGame);
};

class Next : public BasicCommand{
    public:
        void execute(Game& currGame);
};

#endif