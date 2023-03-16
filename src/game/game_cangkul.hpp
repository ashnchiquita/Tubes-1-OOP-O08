#ifndef GAME_CANGKUL_HPP
#define GAME_CANGKUL_HPP

#include "./game_abc.hpp"
using namespace std;

class GameCangkul : public GameABC {
  public:
    GameCangkul();

    void runGame() override;
    void printGameState() override;
    void resetGame() override;
    bool isFinished() override;
};

#endif