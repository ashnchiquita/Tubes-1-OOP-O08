#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../game/game.hpp"

class Command {
    protected:
        Game* game;
    public:
        Command(Game*);
        virtual void execute() = 0;
        virtual ~Command();
};

#endif

