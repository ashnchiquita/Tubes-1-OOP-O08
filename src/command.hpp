#ifndef cmd_hpp
#define cmd_hpp

#include "game_draft.hpp"

class Command {
    public:
        int command;

        Command(int x);
        void execute(Game& currGame);
};

#endif