#include "player.hpp"
using namespace std;

Player::Player() : InventoryHolder(2) {
  this->name = "";
  this->point = 0;
  // this->abilityCard = 0;
}

Player::Player(string name, int point) : InventoryHolder(2) {
  this->name = name;
  this->point = point;
  // this->abilityCard = abilityCard;
}

Player::Player(const Player& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard.first = other.bufferCard.first;
  this->bufferCard.second = other.bufferCard.second;

  this->name = other.name;
  this->point = other.point;
  // this->abilityCard = other.abilityCard;
}

Player& Player::operator=(const Player& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard.first = other.bufferCard.first;
  this->bufferCard.second = other.bufferCard.second;

  this->name = other.name;
  this->point = other.point;
  // this->abilityCard = other.abilityCard;

  return *this;
}

string Player::getName() const { return this->name; }
void Player::setName(string name) { this->name = name; }

int Player::getPoint() const { return this->point; }
void Player::setPoint(int point) { this->point = point; }

// int Player::getAbilityCard() const { return this->abilityCard; }
// void Player::setAbilityCard(int abilityCard) {
//   this->abilityCard = abilityCard;
// }

Card* Player::getAllCards() {
  Card* output = new Card[2];
  output[0] = this->bufferCard.first;
  output[1] = this->bufferCard.second;
  return output;
}

Player& Player::operator<<(const Card& card) {
  if (!this->bufferCard.first.isValidCard()) {
    this->bufferCard.first = card;
  } else if (!this->bufferCard.second.isValidCard()) {
    this->bufferCard.second = card;
  } else {
    cout << "Player hand is full\n";
  }

  return *this;
}

Player& Player::operator>>(Card* card) {
  if (this->bufferCard.second.isValidCard()) {
    *card = this->bufferCard.second;
    this->bufferCard.second = Card();
  } else if (this->bufferCard.first.isValidCard()) {
    *card = this->bufferCard.first;
    this->bufferCard.first = Card();
  } else {
    cout << "Player hand is empty\n";
  }

  return *this;
}

bool Player::operator<(const Player& other) {
  return this->point < other.point;
}

bool Player::operator>(const Player& other) {
  return this->point > other.point;
}

bool Player::operator==(const Player& other) {
  return this->point == other.point;
}