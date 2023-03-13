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
        /* TODO : insert deck */
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
        // void endGame();
        void printGameState();
        
        /* TODO: overload with const */
        Player& getCurrPlayerRef();

        /* TODO: overload with const */
        PlayersList getPlayersList();
        PlayersList& getPlayersListRef();


        /* Basic Command */
        void Double();
        void Half();
        void Next();

        /* Ability Command */
        void Reroll();
        void Quadruple();
        void Quarter();
        void ReverseDirection();
        void SwapCard();
        void SwitchCard();
        void AbilityLess();
};

#endif