#ifndef GAME_HPP
#define GAME_HPP

#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"

class Game {
 private:
  long int gamePoint; //!
  PlayersList playersList;
  Deck mainDeck;
  TableCard mainTable; //!

 public:
  Game();
  
  long int getGamePoint() const; //!
  Player& getCurrPlayerRef();
  Deck& getDeck();
  TableCard& getTableCard(); //!
  PlayersList getPlayersList();
  PlayersList& getPlayersListRef();

  void multiplyGamePoint(float multiplier); //!
  void runTurn(); //!
  void runGame(); //!
  void resetGame();

  bool isFinished();
  void givePoint(); //!
  void printGameState(); //!
};

#endif