#include "inventory_holder.hpp"
using namespace std;

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
