#ifndef GAME_HPP
#define GAME_HPP

#include "../playerslist/playerslist.hpp"
#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/table_card.hpp"


class Game {
    protected:
        int roundCount;
        int turnCountInARound;
        long int gamePoint;
        PlayersList playersList;
        Deck mainDeck;
        TableCard mainTable;

    public:
        Game();
        int getRoundCount();
        int getTurnCountInARound();
        long int getGamePoint();
        void multiplyGamePoint(float multiplier);
        void runTurn();
        void runGame();
        void resetGame();
        bool isComplete();

        /* TODO: implement end game & finishing */
        bool isFinished();
        void endGame();
        void printGameState();
        
        /* TODO: overload with const */
        Player& getCurrPlayerRef();
        Deck& getDeck();
        TableCard& getTableCard();
        PlayersList getPlayersList();
        PlayersList& getPlayersListRef();
};

#endif