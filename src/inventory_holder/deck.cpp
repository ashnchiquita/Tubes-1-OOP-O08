#include "deck.hpp"

#include <vector>
using namespace std;

Deck::Deck() : InventoryHolder(52) {
  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push(Card(i, static_cast<CardColor>(j)));
    }
  }
}

Deck::Deck(const Deck& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;
};

Deck& Deck::operator=(const Deck& other) {
  while (!this->bufferCard.empty()) {
    this->bufferCard.pop();
  }

  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;

  return *this;
}

Deck& Deck::operator<<(const Card& card) {
  if (this->bufferCard.size() < this->getInventoryLimit()) {
    this->bufferCard.push(card);
  } else {
    cout << "Deck is full\n";
  }

  return *this;
}

Deck& Deck::operator>>(Card* card) {
  if (this->bufferCard.empty()) {
    cout << "Deck is empty\n";
  } else {
    *card = this->bufferCard.top();
    this->bufferCard.pop();
  }

  return *this;
}

Card Deck::getTop() const { return this->bufferCard.top(); }

void Deck::resetDeck() {
  while (!this->bufferCard.empty()) {
    this->bufferCard.pop();
  }

  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push(Card(i, static_cast<CardColor>(j)));
    }
  }
};

void Deck::shuffleDeck(){
    // TODO: IMPLEMENTASI RANDOMIZER
};