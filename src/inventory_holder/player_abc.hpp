#ifndef PLAYER_ABC_HPP
#define PLAYER_ABC_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../valuables/card.hpp"
#include "../valuables/ability_card.hpp"
#include "./inventory_holder.hpp"
using namespace std;

template <typename T>
class PlayerABC : public InventoryHolder<T> {
 protected:
  string name;
  long int point;
  static int totalPlayer;

 public:
  // ctor-cctor-dtor
  PlayerABC();
  PlayerABC(string name);
  PlayerABC(string name, long int point);
  PlayerABC(const PlayerABC& other);
  virtual ~PlayerABC() {}
  // services
  string getName() const;
  void setName(string name);

  long int getPoint() const;
  void setPoint(long int point);
  void addPoint(long int point);

  // operator
  virtual PlayerABC& operator<<(const Card& card);
  virtual PlayerABC& operator>>(Card* card);

  bool operator<(const PlayerABC& other) const;
  bool operator>(const PlayerABC& other) const;
  bool operator==(const PlayerABC& other) const;
  
  virtual void clearCards() = 0; 
  virtual void print() = 0;
};

template <typename T>
int PlayerABC<T>::totalPlayer = 0;

template <typename T>
PlayerABC<T>::PlayerABC() : InventoryHolder<T>(2) {
  this->name = "";
  this->point = 0;
  PlayerABC::totalPlayer++;
}

template <typename T>
PlayerABC<T>::PlayerABC(string name)
    : InventoryHolder<T>(2) {
  this->name = name;
  this->point = 0;
  PlayerABC::totalPlayer++;
}

template <typename T>
PlayerABC<T>::PlayerABC(string name, long int point)
    : InventoryHolder<T>(2) {
  this->name = name;
  this->point = point;
  PlayerABC::totalPlayer++;
}

template <typename T>
PlayerABC<T>::PlayerABC(const PlayerABC<T>& other): InventoryHolder<T>(2) {
  this->name = other.name;
  this->point = other.point;
  this->inventoryLimit = other.inventoryLimit;
}

template <typename T>
string PlayerABC<T>::getName() const { return this->name; }

template <typename T>
void PlayerABC<T>::setName(string name) { this->name = name; }

template <typename T>
long int PlayerABC<T>::getPoint() const { return this->point; }

template <typename T>
void PlayerABC<T>::setPoint(long int point) { this->point = point; }

template <typename T>
void PlayerABC<T>::addPoint(long int point) { this->point += point; };

template <typename T>
PlayerABC<T>& PlayerABC<T>::operator<<(const Card& card) {
  return *this;
}

template <typename T>
PlayerABC<T>& PlayerABC<T>::operator>>(Card* card) {
  return *this;
}

template <typename T>
bool PlayerABC<T>::operator<(const PlayerABC<T>& other) const {
  return this->point < other.point;
}

template <typename T>
bool PlayerABC<T>::operator>(const PlayerABC<T>& other) const {
  return this->point > other.point;
}

template <typename T>
bool PlayerABC<T>::operator==(const PlayerABC<T>& other) const {
  return this->bufferCard == other.bufferCard && this->point == other.point && this->name == other.name;
}

#endif