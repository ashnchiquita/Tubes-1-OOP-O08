#ifndef PLAYERSLIST_HPP
#define PLAYERSLIST_HPP

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#include "../inventory_holder/player.hpp"

using namespace std;

class PlayersList {
    private:
        vector<Player> list;
        int turnCountInARound, roundCount;

        void delFirstInsertLast();

    public:
        PlayersList();
        void addPlayer(Player p);
        int getRoundCount() const;
        int getTurnCountInARound() const;
        void changeTurn();
        void changeRound();
        void print();
        void printSequence();
        void printSequenceOrder();
        void printSequencePoints();
        
        PlayersList operator-(const Player& other);

        Player& getCurrPlayer();
        Player& getPlayerAt(int i);

        void reversePlayers();
        void reset();
        int getSize();

        PlayersList getNextRound();
        PlayersList getRemainingTurns();

        /* TODO: implement winner searching */
        bool isComplete();

        // setelah hadiah dikasih
        Player highestPoint() const;
        bool hasWinner() const;
        bool isNewRound() const;
        bool restrictTable() const;
        PlayersList getLeaderboard() const;

        bool restrictCommand() const;
        Player& findPlayer(const Player& other);
};

#endif