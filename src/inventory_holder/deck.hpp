#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <string>

#include "inventory_holder.hpp"
#include "./valuables/card.hpp"
using namespace std;

class deck : public InventoryHolder {
public:
    // General Methods
    deck();                     // ctor
    deck(int cards);
    deck(const deck& p);        // cctor
    ~deck();                    // dtor

    // Methods
    void resetDeck();

};


#endif