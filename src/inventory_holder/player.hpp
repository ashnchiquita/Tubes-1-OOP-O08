#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "../valuables/card.hpp"
#include "../valuables/ability_card.hpp"
#include "./inventory_holder.hpp"

class Player : public InventoryHolder<pair<Card, Card> > {
 private:
  string name;
  long int point;
  static int totalPlayer;
  AbilityCard abilityCard;

 public:
  // ctor-cctor-dtor
  Player();
  Player(string name);
  Player(string name, long int point);
  Player(const Player& other);
  Player& operator=(const Player& other);

  // services
  string getName() const;
  void setName(string name);

  long int getPoint() const;
  void setPoint(long int point);
  void addPoint(long int point);

  // Ability Card
  AbilityCard& getAbilityRef();
  AbilityCard getAbility() const;

  // IDX 0 for LeftCard, IDX 1 for RightCard
  Card getCard(int idx);
  void setCard(int idx, Card card);

  vector<Card> getAllCards() const;

  // operator
  Player& operator<<(const Card& card) override;
  Player& operator>>(Card* card) override;

  bool operator<(const Player& other) const;
  bool operator>(const Player& other) const;
  bool operator==(const Player& other) const;

  void print() override;
  void PlayerASCII();
};

#endif