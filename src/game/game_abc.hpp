#ifndef GAME_ABC_HPP
#define GAME_ABC_HPP

#include <string>

#include "../playerslist/playerslist.hpp"
#include "../inventory_holder/deck.hpp"
#include "../valuables/card.hpp"
#include "../input_handler/command_handler.hpp"
#include "../input_handler/file_handler.hpp"

using namespace std;

class GameABC {
  protected:
    PlayersList playersList;
    Deck mainDeck;

  public:
    GameABC(int playerCount);

    Player& getCurrPlayerRef();
    Deck& getDeck();
    PlayersList getPlayersList();
    PlayersList& getPlayersListRef();

    virtual void runGame() = 0;
    virtual void printGameState() = 0;
    virtual void resetGame() = 0;
    virtual bool isFinished() = 0;
};

#endif