#include "player.hpp"

#include <map>
using namespace std;

int Player::totalPlayer = 0;

Player::Player() : InventoryHolder<pair<Card, Card> >(2) {
  this->name = "";
  this->point = 0;
  Player::totalPlayer++;
}

Player::Player(string name)
    : InventoryHolder<pair<Card, Card> >(2) {
  this->name = name;
  this->point = 0;
  Player::totalPlayer++;
}

Player::Player(string name, long int point)
    : InventoryHolder<pair<Card, Card> >(2) {
  this->name = name;
  this->point = point;
  Player::totalPlayer++;
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
AbilityCard& Player::getAbilityRef() { return this->abilityCard;}

AbilityCard Player::getAbility() const { return this->abilityCard; }

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

vector<Card> Player::getAllCards() const {
  vector<Card> output;
  output.push_back(this->bufferCard.first);
  output.push_back(this->bufferCard.second);
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
    this->bufferCard.first = Card(); 
  } else { 
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
  return this->bufferCard == other.bufferCard && this->point == other.point && this->name == other.name && this->abilityCard == other.abilityCard;
}

void Player::print() {
  char space = ' ';
  char dash = '_';
  int num = 45;
  /* DEBUG */
  // cout << "Name: " << this->name << endl;
  cout << string(num, dash) << endl << endl;
  cout << " Point    : " << this->point << ""<< endl;
 
  cout << " Ability  : ";
  this->getAbility().displayAbility();
  cout << endl;
  cout << " Cards    : ";
  this->bufferCard.first.displayCard();
  cout << ", ";
  this->bufferCard.second.displayCard();
  cout << endl;
  cout << string(num, dash) << endl;
}

void Player::PlayerASCII() {
  string firstColor, secondColor;
  CardColor card1 = this->getCard(0).getColor();
  if (card1== CardColor::GREEN ){ firstColor = "\033[32m";}
  else if (this->getCard(0).getColor() == CardColor::BLUE){ firstColor = "\033[34m";}
  else if (this->getCard(0).getColor() == CardColor::RED){ firstColor = "\033[31m";}
  else if (this->getCard(0).getColor() == CardColor::YELLOW){ firstColor = "\033[33m";}

  if (this->getCard(1).getColor() == CardColor::GREEN ){ secondColor = "\033[32m";}
  else if (this->getCard(1).getColor() == CardColor::BLUE){ secondColor = "\033[34m";}
  else if (this->getCard(1).getColor() == CardColor::RED){ secondColor = "\033[31m";}
  else if (this->getCard(1).getColor() == CardColor::YELLOW){ secondColor = "\033[33m";}
  char space = ' ';
  
  cout << firstColor; this->getCard(0).displayCard(); cout << secondColor << "    "; this->getCard(1).displayCard(); cout << endl;
        cout << firstColor << "┌─────────┐   " << secondColor << "┌─────────┐    \n";
        cout << firstColor <<"│"<<this->getCard(0).getNum()<< string(1-this->getCard(0).getNum()/10, space)<<"       │   " << secondColor << "│"<< this->getCard(1).getNum() << string(1-this->getCard(0).getNum()/10, space) <<"       │   \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │    \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│    ♣    │   " << secondColor << "│    ♣    │    \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│       "<<string(1-this->getCard(0).getNum()/10, space)<<this->getCard(0).getNum()<<"│   " << secondColor << "│       "<<string(1-this->getCard(1).getNum()/10, space)<< this->getCard(1).getNum() <<"│     \n";
        cout << firstColor <<"└─────────┘   " << secondColor << "└─────────┘     \n";
}
