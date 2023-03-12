#include <iostream>
#include "game/game.hpp"

int main(int argc, const char** argv) {
    Game g;
    do {
        g.runGame();
        g.resetGame();
    } while (!g.isFinished());
    
    return 0;
}
// g++ -o main main.cpp game_draft.cpp playerslist.cpp player.cpp command.cpp