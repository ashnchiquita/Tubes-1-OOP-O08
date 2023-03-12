#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <iostream>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"
using namespace std;

class Deck : public InventoryHolder<vector <Card> > {
public:
  // General Methods
  Deck();  // ctor
  Deck(const Deck& other);
  Deck& operator=(const Deck& other);

  Deck& operator<<(const Card& card) override;
  Deck& operator>>(Card* card) override;

  // Methods
  Card getTop() const;
  void resetDeck();
  void shuffleDeck();
};

#endif