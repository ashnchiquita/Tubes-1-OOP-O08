#include <iostream>
#include "game_draft.hpp"

int main(int argc, const char** argv) {
    Game g;
    g.runGame();
    return 0;
}
// g++ -o main main.cpp game_draft.cpp playerslist.cpp player.cpp command.cpp