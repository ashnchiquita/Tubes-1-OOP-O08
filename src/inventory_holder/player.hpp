#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"

class Player : public InventoryHolder<pair <Card, Card> > {
 private:
  const int ID;
  string name;
  int point;
  static int totalPlayer;
    /* TODO: implement ability card */
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
  int getID() const;

  int getPoint() const;
  void setPoint(int point);

  // int getAbilityCard() const;
  // void setAbilityCard(int abilityCard);

  // IDX 0 for LeftCard, IDX 1 for RightCard
  Card getCard(int idx);
  void setCard(int idx, Card card);

  Card* getAllCards();
  // resetCards();
  // void setCards(Card* card);

  // operator
  Player& operator<<(const Card& card) override;
  Player& operator>>(Card* card) override;
  
  bool operator<(const Player& other);
  bool operator>(const Player& other);
  bool operator==(const Player& other);

  void print();
};

#endif