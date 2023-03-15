#ifndef GAME_CANGKUL_HPP
#define GAME_CANGKUL_HPP

#include <string>

#include "../playerslist/playerslist.hpp"
#include "../inventory_holder/deck.hpp"
#include "../valuables/card.hpp"
#include "../input_handler/command_handler.hpp"
#include "../input_handler/file_handler.hpp"

using namespace std;

class GameABC {
  private:
    PlayersList playersList;
    Deck mainDeck;

    void resetGame();
    bool isFinished();

  public:
    GameABC(int playerCount);

    Player& getCurrPlayerRef();
    Deck& getDeck();
    PlayersList getPlayersList();
    PlayersList& getPlayersListRef();

    void runGame();
    void printGameState();
};

#endif