#include "deck.hpp"
#include "../algorithm/algos.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

Deck::Deck() : InventoryHolder<vector<Card> >(52) {
  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push_back(Card(i, static_cast<CardColor>(j)));
    }
  }
  this->shuffleDeck();
}

Deck::Deck(vector<Card> cardArray) { /* TODO: sambungin sama file IO */
  for (int i = 0; i < 52; i++) {
    *this << cardArray[i];
  }
}

Deck::Deck(const Deck& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;
}

Deck& Deck::operator=(const vector<Card> cardArray) {
  this->bufferCard.clear();
  this->inventoryLimit = 52;
  for (int i = 0; i < 52; i++) {
    *this << cardArray[i];
  }

  return *this;
}

Deck& Deck::operator=(const Deck& other) {
  this->bufferCard.clear();
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;

  return *this;
}

Deck& Deck::operator<<(const Card& card) {
  // TODO: if card in operator then do nothing / throw exc
  if (this->bufferCard.size() < this->getInventoryLimit()) {
    this->bufferCard.push_back(card);
  } else {
    cout << "Deck is full\n";
  }

  return *this;
}

Deck& Deck::operator>>(Card* card) {
  if (this->bufferCard.empty()) {
    cout << "Deck is empty\n";
  } else {
    *card = this->bufferCard[this->bufferCard.size() - 1];
    this->bufferCard.pop_back();
  }

  return *this;
}

Card Deck::getTop() const {
  return this->bufferCard[this->bufferCard.size() - 1];
}
int Deck::getSize() const { return this->bufferCard.size(); }
void Deck::resetDeck() {
  this->bufferCard.clear();

  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push_back(Card(i, static_cast<CardColor>(j)));
    }
  }
};

void Deck::shuffleDeck() {
  Algos r;
  r.iterShuffle(&this->bufferCard);
};

void Deck::print() {
  if (this->bufferCard.size() == 0) {
    cout << "Deck kosong" << endl;
  } else {
    vector<Card>::reverse_iterator it;
    cout << "from top: " << endl;
    for (it = this->bufferCard.rbegin(); it != this->bufferCard.rend(); ++it) {
      (*it).displayCard();
    }
  }
}

void Deck::clearCards() {
  this->bufferCard.clear();
}