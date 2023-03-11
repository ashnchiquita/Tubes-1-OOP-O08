#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
#include "./action/action.hpp"
#include "./inventory_holder/player.hpp"
#include "./inventory_holder/deck.hpp"
#include "./game_engine/game_engine.hpp"
#include "./inventory_holder/inventory_holder.hpp"
using namespace std;

class AbilityCmd : public Action{
    protected:
        PlayersQueue* bufferPlayerQueue;
        Deck* bufferDeck;
        Turn currPlayer;
        Game gamePoints;
        InventoryHolder* playerCard;
        bool checkAbilityLess = false;
    public:
        AbilityCmd();
        virtual bool isAbilityless() = 0;
        ~AbilityCmd();
};

class Reroll : public AbilityCmd{
    void execute(InventoryHolder &p);
};

class Quadruple : public AbilityCmd{
    void execute(double points);
    //multiplier = 4
};

class Quarter : public AbilityCmd{
    void execute(double points);
    //multiplier = 0.25
};

class ReverseDirection : public AbilityCmd{
    void reverseArray(PlayersQueue p1[], int start, int end);
    void execute(PlayersQueue pq[], int ccplayer);

};

class SwapCard : public AbilityCmd{
    void SwapCard::execute(InventoryHolder pc1[], InventoryHolder pc2[]);
};

class SwitchCard : public AbilityCmd{
    void SwitchCard::execute(InventoryHolder pc1[], InventoryHolder pc2[]);
};

class AbilityLess : public AbilityCmd{
    void execute();
};

#endif
