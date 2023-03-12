#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include "../game/game.hpp"
using namespace std;

class Command {
    public:
        Command();
        virtual void execute(Game& currGame) = 0;
};

#endif