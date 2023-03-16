#ifndef GAME_CANGKUL_HPP
#define GAME_CANGKUL_HPP

#include "./game_abc.hpp"
#include "../inventory_holder/player_cangkul.hpp"
using namespace std;

class GameCangkul : public GameABC<PlayerCangkul> {
  public:
    GameCangkul();

    void runGame() override;
    void printGameState() override;
    void resetGame() override;
    bool isFinished() override;
};

#endif