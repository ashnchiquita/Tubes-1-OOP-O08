#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

#include <iostream>
#include <string>
using namespace std;

class InventoryHolder {
protected:
    Card* bufferCard;
public:
    // ctor-cctor-dtor
    InventoryHolder(); 
    InventoryHolder(int cards);
    InventoryHolder(const InventoryHolder& p);
    ~InventoryHolder();

    // services
    void addCard();
    void removeCard();

    // operators
    InventoryHolder& operator+ (const InventoryHolder& holder);
    InventoryHolder& operator- (const InventoryHolder& holder);
};


#endif