#ifndef GAME_CANGKUL_HPP
#define GAME_CANGKUL_HPP

#include "./game_abc.hpp"
#include "../inventory_holder/player_cangkul.hpp"
using namespace std;

class GameCangkul : public GameABC<PlayerCangkul> {
  private:
    void removeCardAt(int cardIdx, int playerIdx);
    Deck tempDeck;

  public:
    GameCangkul();

    void ambilKartu(int);

    void runGame() override;
    void printGameState() override;
    void resetGame() override;
    bool isFinished() override;
};

#endif