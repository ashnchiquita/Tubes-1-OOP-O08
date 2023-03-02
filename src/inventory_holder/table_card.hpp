#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <string>
#include "inventory_holder.hpp"
#include "./valuables/card.hpp"
using namespace std;

class TableCard : public InventoryHolder {
protected: 
    Card* bufferCardRevealed;
public:
    // ctor-cctor-dtor
    TableCard();       
    TableCard(int cards);
    TableCard(const TableCard& p);
    ~TableCard();  

    // services


};


#endif