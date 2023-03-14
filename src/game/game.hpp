#ifndef GAME_HPP
#define GAME_HPP

#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"
#include "../valuables/combo.hpp"

class Game {
 private:
  long int gamePoint;
  PlayersList playersList;
  Deck mainDeck;
  TableCard mainTable;

 public:
  Game();
  long int getGamePoint();
  void multiplyGamePoint(float multiplier);
  void runTurn();
  void runGame();
  void resetGame();

  /* TODO: implement end game & finishing */
  bool isFinished();
  void givePoint();
  void printGameState();

  /* TODO: overload with const */
  Player& getCurrPlayerRef();
  Deck& getDeck();
  TableCard& getTableCard();
  PlayersList getPlayersList();
  PlayersList& getPlayersListRef();
};

#endif