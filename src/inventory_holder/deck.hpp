#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <iostream>
#include <vector>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"
using namespace std;

class Deck : public InventoryHolder<vector<Card> > {
 public:
  // General Methods
  Deck();  // ctor
  Deck(vector<Card>);
  Deck(const Deck& other);
  Deck& operator=(const vector<Card>);
  Deck& operator=(const Deck& other);

  Deck& operator<<(const Card& card) override;
  Deck& operator>>(Card* card) override;
  void print() override;

  // Methods
  Card getTop() const;
  int getSize() const;
  // Card* getTwo() const;
  void resetDeck();
  void shuffleDeck();
};

#endif



