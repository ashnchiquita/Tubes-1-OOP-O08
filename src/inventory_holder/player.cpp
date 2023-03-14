#include "player.hpp"
#include <map>
using namespace std;

int Player::totalPlayer = 0;

Player::Player() : InventoryHolder<pair<Card, Card> >(2) {
  this->name = "";
  this->point = 0;
  Player::totalPlayer++;
  this->abilityCard = AbilityType::NULLABILITY;
}

Player::Player(string name, long int point)
    : InventoryHolder<pair<Card, Card> >(2) {
  this->name = name;
  this->point = point;
  Player::totalPlayer++;
  this->abilityCard = AbilityType::NULLABILITY;
}

Player::Player(const Player& other) : InventoryHolder<pair<Card, Card> >(2) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard.first = other.bufferCard.first;
  this->bufferCard.second = other.bufferCard.second;

  this->name = other.name;
  this->point = other.point;
  this->abilityCard = other.abilityCard;
}

Player& Player::operator=(const Player& other) {
  this->inventoryLimit = other.inventoryLimit;
  this->bufferCard.first = other.bufferCard.first;
  this->bufferCard.second = other.bufferCard.second;

  this->name = other.name;
  this->point = other.point;
  this->abilityCard = other.abilityCard;

  return *this;
}

string Player::getName() const { return this->name; }
void Player::setName(string name) { this->name = name; }
long int Player::getPoint() const { return this->point; }
void Player::setPoint(long int point) { this->point = point; }
void Player::addPoint(long int point) { this->point += point; };

/* ABILITY CARD */
AbilityType Player::getType() const { return this->abilityCard; }
void Player::setAbilityType(AbilityType type) { this->abilityCard = type; }
bool Player::getAbilityCardStatus() const { return this->abilityCard != AbilityType::NULLABILITY; }
void Player::setAbilityCardStatus(bool status) { 
  if (!status) {
    this->abilityCard = AbilityType::NULLABILITY;
  }
}

Card Player::getCard(int idx) {
  if (idx == 0) {
    return this->bufferCard.first;
  } else { // idx == 1
    return this->bufferCard.second;
  } // TODO : kalo mo pasang if 0 else if 1, pake else terus throw exception out of bounds
}

void Player::setCard(int idx, Card card) {
  if (idx == 0) {
    bufferCard.first = card;
  } else if (idx == 1) {
    bufferCard.second = card;
  }
}

// TODO: kenapa ga pake reference ke card dia aja? kalo gini bakal memory leak, tp nanti aja
Card* Player::getAllCards() const {
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
  } else { // TODO: pake exception
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
    this->bufferCard.first = Card(); // TODO:
  } else { // TODO: pake exception
    cout << "Player hand is empty\n";
  }

  return *this;
}

bool Player::operator<(const Player& other) const {
  return this->point < other.point;
}

bool Player::operator>(const Player& other) const {
  return this->point > other.point;
}

bool Player::operator==(const Player& other) const {
  return this->point == other.point;
}

void Player::print() {
  cout << "Name: " << this->name << endl;
  cout << "Point: " << this->point << endl;

 
  cout << "Ability: ";
  displayAbility();
  /* TODO: implement hand card print */
  // cout << "Cards: " <<  << endl;
}

void Player::displayAbility() {
  map<AbilityType, string> typeMap;
  typeMap[AbilityType::REROLL] = "reroll";
  typeMap[AbilityType::QUADRUPLE] = "quadruple";
  typeMap[AbilityType::QUARTER] = "quarter";
  typeMap[AbilityType::REVERSE] = "reverse";
  typeMap[AbilityType::SWAP] = "swap";
  typeMap[AbilityType::SWITCH] = "switch";
  typeMap[AbilityType::ABILITYLESS] = "abilityless";
  typeMap[AbilityType::NULLABILITY] = "nullability";

  cout << "Kartu " << typeMap[this->abilityCard] << endl;
}