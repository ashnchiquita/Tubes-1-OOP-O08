#include "deck.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <string> 
using namespace std;

Deck::Deck() : InventoryHolder(52) {
  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push_back(Card(i, static_cast<CardColor>(j)));
    }
  }
}

Deck::Deck(string filename) {
  // ifstream configFile(filename);
  // string cardLine, token;
  // Card card;

  // while(getline(configFile, cardLine)){
  //   // cout << cardLine << endl;
  //   int pos = cardLine.rfind(" ");
  // }
};

Deck::Deck(const Deck& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;
};

Deck& Deck::operator=(const Deck& other) {
  this->bufferCard.clear();
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard = other.bufferCard;

  return *this;
}

Deck& Deck::operator<<(const Card& card) {
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

Card Deck::getTop() const { return this->bufferCard[this->bufferCard.size() - 1]; }

void Deck::resetDeck() {
  this->bufferCard.clear();

  for (int i = 1; i <= 13; i++) {
    for (int j = 0; j < 4; j++) {
      this->bufferCard.push_back(Card(i, static_cast<CardColor>(j)));
    }
  }
};

void Deck::shuffleDeck() {
    auto rng = default_random_engine();
    shuffle(this->bufferCard.begin(), this->bufferCard.end(), rng);
};