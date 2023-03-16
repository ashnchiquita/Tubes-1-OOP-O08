#include "game/game_poker.hpp"

/* TODO: handle Y/N input untuk retry */
int main() {
    GamePoker g;
    do {
        g.runGame();
        if (!g.isFinished()) {
            g.resetGame();
        }
    } while (!g.isFinished());
    
    return 0;
}