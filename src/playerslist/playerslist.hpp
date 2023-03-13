#ifndef PLAYERSLIST_HPP
#define PLAYERSLIST_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../inventory_holder/player.hpp"

using namespace std;

class PlayersList {
    private:
        vector<Player> list;

    public:
        PlayersList();
        void addPlayer(Player p);
        void changeTurn();
        void changeRound();
        void print();

        // vector<Player>::iterator highCard();
        
        PlayersList operator-(const PlayersList& other);
        PlayersList operator-(const Player& other);

        Player& getCurrPlayer();
        Player& getPlayerAt(int i);

        void reversePlayers(int turnCount);
        void reset();
        int getSize();

        PlayersList getNextRound(int turnCount);
        PlayersList getRemainingTurns(int turnCount);

        /* TODO: implement winner searching */
        // bool hasWinner();
        // Player& findWinner();
};

#endif