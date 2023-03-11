#ifndef pl_hpp
#define pl_hpp

#include <string>
#include <iostream>
#include <vector>
#include "player.hpp"

using namespace std;

class PlayersList {
    public:
        vector<Player> pq;

        PlayersList();
        void addPlayer(Player p);
        void changeTurn();
        void changeRound();
        void print();
        vector<Player>::iterator highCard();
};

#endif