#include "game/game.hpp"

/* TODO: handle Y/N input untuk retry */
int main() {
    Game g;
    do {
        g.runGame();
        if (!g.isFinished()) {
            g.resetGame();
        }
    } while (!g.isFinished());
    
    return 0;
}