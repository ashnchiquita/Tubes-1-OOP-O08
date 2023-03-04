#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"

class Player : public InventoryHolder<pair <Card, Card> > {
 protected:
  string name;
  int point;
  // int abilityCard;

 public:
  // ctor-cctor-dtor
  Player();
  Player(string name, int point);
  Player(const Player& other);
  Player& operator=(const Player& other);

  // services
  string getName() const;
  void setName(string name);

  int getPoint() const;
  void setPoint(int point);

  // int getAbilityCard() const;
  // void setAbilityCard(int abilityCard);

  Card* getAllCards();

  // operator
  Player& operator<<(const Card& card) override;
  Player& operator>>(Card* card) override;
  bool operator<(const Player& other);
  bool operator>(const Player& other);
  bool operator==(const Player& other);
};

#endif