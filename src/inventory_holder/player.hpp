#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"

enum class AbilityType {
  REROLL,
  QUADRUPLE,
  QUARTER,
  REVERSE,
  SWAP,
  SWITCH,
  ABILITYLESS,
  NULLABILITY
};

class Player : public InventoryHolder<pair<Card, Card> > {
 private:
  string name;
  long int point;
  static int totalPlayer;
  /* TODO: implement ability card */
  AbilityType abilityCard;
  bool abilityStatus;

 public:
  // ctor-cctor-dtor
  Player();
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
  AbilityType getType() const;
  void setAbilityType(AbilityType type);
  bool getAbilityCardStatus() const;
  void setAbilityCardStatus(bool status);
  void displayAbility();

  // IDX 0 for LeftCard, IDX 1 for RightCard
  Card getCard(int idx);
  void setCard(int idx, Card card);

  Card* getAllCards() const;
  // resetCards();
  // void setCards(Card* card);

  // operator
  Player& operator<<(const Card& card) override;
  Player& operator>>(Card* card) override;

  bool operator<(const Player& other) const;
  bool operator>(const Player& other) const;
  bool operator==(const Player& other);

  void print();
};

#endif