#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include <iostream>
#include <string>
#include <vector>

#include "../valuables/card.hpp"
#include "./inventory_holder.hpp"

class TableCard : public InventoryHolder <vector <Card> > {
 public:
  // ctor-cctor-dtor
  TableCard();
  TableCard(const TableCard& other);
  TableCard& operator=(const TableCard& other);

  TableCard& operator<<(const Card& card) override;
  TableCard& operator>>(Card* card) override;

  // services
  void clearCards() override;
  vector<Card> getAllCards();
  void ASCIITable();
  void print() override;

  int getSize() const;
};

#endif



