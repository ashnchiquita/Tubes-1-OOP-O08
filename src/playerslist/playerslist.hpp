#ifndef PLAYERSLIST_HPP
#define PLAYERSLIST_HPP

#include "../inventory_holder/player.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

class PlayersList {
    private:
        vector<Player> list;
        int turnCountInARound, roundCount;

        void delFirstInsertLast();
        void undoDelFirstInsertLast();

    public:
        PlayersList();
        void addPlayer(Player p);
        int getRoundCount() const;
        int getTurnCountInARound() const;
        void changeTurn();
        void undoChangeTurn();
        void changeRound();
        void undoChangeRound();
        void print();
        void printSequence();
        void printSequenceOrder();
        void printSequencePoints();
        
        PlayersList operator-(const Player& other);

        Player& getCurrPlayer();
        Player& getPlayerAt(int i);

        void reversePlayers();
        void afterReverse();
        void reset();
        int getSize();

        PlayersList getNextRound();
        PlayersList getRemainingTurns();

        /* TODO: implement winner searching */
        bool isComplete();
        bool isNextComplete();

        // setelah hadiah dikasih
        Player highestPoint() const;
        bool hasWinner() const;
        bool isNewRound() const;
        bool restrictTable() const;
        PlayersList getLeaderboard() const;

        bool restrictCommand() const;
        Player& findPlayer(const Player& other);
        bool hasAbility() const;
};

#endif