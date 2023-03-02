#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "inventory_holder.hpp"
#include "./valuables/card.hpp"

using namespace std;

class Player : public InventoryHolder {
protected: 
    string name;
    int point;
    int ability_card;
public:
    // ctor-cctor-dtor
    Player();              
    Player(string name, int point, int ability_card);
    Player(const Player& p);
    ~Player();      

    // services
    string getName() const;
    void setName(string name);

    int getPoint() const;
    void setPoint(int point);

    Card getAbilityCard() const;
    void setAbilityCard() const;

    // operator
    Player& operator< (const Player& holder);
    Player& operator> (const Player& holder);
    Player& operator== (const Player& holder);
};


#endif