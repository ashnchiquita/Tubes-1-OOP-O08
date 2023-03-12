#ifndef GAME_HPP
#define GAME_HPP

#include "playerslist.hpp"

class Game {
    private:
        int roundCount;
        int turnCountInARound;
        long int gamePoint;
        PlayersList playersList;
        /* TODO : insert deck */
        // Deck mainDeck

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
        // void endGame();
        void printGameState();
        
        /* TODO: overload with const */
        Player& getCurrPlayerRef();

        /* TODO: overload with const */
        PlayersList getPlayersList();
        PlayersList& getPlayersListRef();
};

#endif