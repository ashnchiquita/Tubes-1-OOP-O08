#include "table_card.hpp"
using namespace std;

TableCard::TableCard() : InventoryHolder<vector <Card> >(5) {}

TableCard::TableCard(const TableCard& other) {
  this->inventoryLimit = other.inventoryLimit;
  for (Card card : other.bufferCard) {
    this->bufferCard.push_back(card);
  }
}

TableCard& TableCard::operator=(const TableCard& other) {
  while (!this->bufferCard.empty()) {
    this->bufferCard.pop_back();
  }

  this->inventoryLimit = other.inventoryLimit;
  for (Card card : other.bufferCard) {
    this->bufferCard.push_back(card);
  }

  return *this;
}

TableCard& TableCard::operator<<(const Card& card) {
  if (this->bufferCard.size() < this->getInventoryLimit()) {
    this->bufferCard.push_back(card);
  } else { // TODO: pake exception
    cout << "Table is full\n";
  }

  return *this;
}

TableCard& TableCard::operator>>(Card* card) {
  if (!this->bufferCard.empty()) {
    *card = this->bufferCard[this->bufferCard.size() - 1];
    this->bufferCard.pop_back();
  } else { // TODO: pake exception
    cout << "Table is empty\n";
  }

  return *this;
}

Card* TableCard::getAllCards() {
  Card* output = new Card[this->bufferCard.size()];
  for (int i = 0; i < this->bufferCard.size(); i++) {
    output[i] = this->bufferCard[i];
  }
  return output;
}

void TableCard::print() {
  if (this->bufferCard.size() == 0) {
    cout << "Table Card kosong" << endl;
  } else {
    vector <Card>::iterator it;
    for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it) {
      (*it).displayCard();
    }
  }
}

int TableCard::getSize() const { return this->bufferCard.size(); }