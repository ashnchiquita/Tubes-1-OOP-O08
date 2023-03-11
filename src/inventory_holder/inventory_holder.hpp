#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

#include <iostream>
#include <type_traits>
#include <vector>

#include "../valuables/card.hpp"

template <typename T>
class InventoryHolder {
 protected:
  T bufferCard;
  int inventoryLimit;

 public:
  // ctor-cctor-dtor
  InventoryHolder();
  InventoryHolder(int inventoryLimit);

  int getInventoryLimit();
  void setInventoryLimit(int inventoryLimit);

  // services
  // void addCard();
  // void removeCard();

  // operators
  virtual InventoryHolder& operator<<(const Card& card) = 0;
  virtual InventoryHolder& operator>>(Card* card) = 0;
};

#endif