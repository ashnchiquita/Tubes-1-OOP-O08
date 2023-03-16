#ifndef GAME_POKER_HPP
#define GAME_POKER_HPP

#include <iostream>
#include <string>

#include "./game_abc.hpp"

#include "../exception/game_exception.hpp"
#include "../exception/command_exception.hpp"
#include "../valuables/combo.hpp"
#include "../valuables/combine.hpp"
#include "../input_handler/command_handler.hpp"
#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/inventory_holder.hpp"
#include "../inventory_holder/player_poker.hpp"
#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"
#include "../randomizer/randomizer.hpp"
#include "../valuables/card.hpp"
#include "../input_handler/file_handler.hpp"

using namespace std;

class GamePoker : public GameABC<PlayerPoker> {
  protected:
    long int gamePoint;
    TableCard mainTable;

  public:
    GamePoker();

    long int getGamePoint() const;
    TableCard& getTableCard();

    void runTurn();
    void givePoint();
    void resetGame() override;
    bool isFinished() override;
    void runGame() override;
    void printGameState() override;
    
    void multiplyGamePoint(float multiplier);
};

#endif