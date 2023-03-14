#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

#include <iostream>
#include <type_traits>
#include <vector>

#include "../valuables/card.hpp"
using namespace std;

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

  // operators
  virtual InventoryHolder& operator<<(const Card& card) = 0;
  virtual InventoryHolder& operator>>(Card* card) = 0;
  virtual void print() = 0;
};



template <typename T>
InventoryHolder<T>::InventoryHolder() {
  this->inventoryLimit = 0;
}

template <typename T>
InventoryHolder<T>::InventoryHolder(int inventoryLimit) {
  this->inventoryLimit = inventoryLimit;
}

template <typename T>
int InventoryHolder<T>::getInventoryLimit() {
  return this->inventoryLimit;
}

template <typename T>
void InventoryHolder<T>::setInventoryLimit(int inventoryLimit) {
  this->inventoryLimit = inventoryLimit;
}

#endif