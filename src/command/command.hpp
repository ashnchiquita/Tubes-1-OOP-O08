#ifndef COMMAND_HPP
#define COMMAND_HPP

// #include "../game/game.hpp"
#include "../game/game_poker.hpp"
// #include "../game/game_abc.hpp"

class Command {
    protected:
        GamePoker* game;
    public:
        Command(GamePoker*);
        virtual void execute() = 0;
        virtual ~Command();
};

#endif

