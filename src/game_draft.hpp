#ifndef gd_hpp
#define gd_hpp
#include "playerslist.hpp"

class Game {
    public:
    int roundCount;
    int turnCountInARound;
    long int gamePoint;
    PlayersList pl;

    Game();
    void addRound();
    void runTurn();
    void runGame();
    bool isFinished();
    void endGame();
    void printGameState();
};

#endif