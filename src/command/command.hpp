#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include "../game/game.hpp"
using namespace std;

class Command {
    protected:
        Game* game;
    public:
        Command(Game*);
        virtual void execute() = 0;
        virtual ~Command();
};

#endif