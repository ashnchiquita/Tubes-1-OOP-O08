#include "./player_poker.hpp"
#include <iostream>
using namespace std;

PlayerPoker::PlayerPoker(): PlayerABC() {}

PlayerPoker::PlayerPoker(string name): PlayerABC(name) {};

PlayerPoker::PlayerPoker(string name, long int point): PlayerABC(name, point) {};

PlayerPoker::PlayerPoker(const PlayerPoker& other) : PlayerABC(other) {
  this->bufferCard.first = other.bufferCard.first;
  this->bufferCard.second = other.bufferCard.second;

  this->abilityCard = other.abilityCard;
}

void PlayerPoker::clearCards(){
  Card temp;
  *this >> &temp;
  *this >> &temp;
}

AbilityCard& PlayerPoker::getAbilityRef() { return this->abilityCard;}

AbilityCard PlayerPoker::getAbility() const { return this->abilityCard;}

// IDX 0 for LeftCard, IDX 1 for RightCard
Card PlayerPoker::getCard(int idx) {
  if (idx == 0) {
    return this->bufferCard.first;
  } else { // idx == 1
    return this->bufferCard.second;
  } // TODO : kalo mo pasang if 0 else if 1, pake else terus throw exception out of bounds
}

void PlayerPoker::setCard(int idx, Card card) {
  if (idx == 0) {
    bufferCard.first = card;
  } else if (idx == 1) {
    bufferCard.second = card;
  }
}

vector<Card> PlayerPoker::getAllCards() const {
  vector<Card> output;
  output.push_back(this->bufferCard.first);
  output.push_back(this->bufferCard.second);
  return output;
}

// operator
PlayerPoker& PlayerPoker::operator<<(const Card& card) {
  if (!this->bufferCard.first.isValidCard()) {
    this->bufferCard.first = card;
  } else if (!this->bufferCard.second.isValidCard()) {
    this->bufferCard.second = card;
  } else { // TODO: pake exception
    std::cout << "Player hand is full\n";
  }

  return *this;
}

PlayerPoker& PlayerPoker::operator>>(Card* card) {
  if (this->bufferCard.second.isValidCard()) {
    *card = this->bufferCard.second;
    this->bufferCard.second = Card();
  } else if (this->bufferCard.first.isValidCard()) {
    *card = this->bufferCard.first;
    this->bufferCard.first = Card(); 
  } else { 
    std::cout << "Player hand is empty\n";
  }

  return *this;
}

void PlayerPoker::print() {
  char space = ' ';
  char dash = '_';
  int num = 45;
  /* DEBUG */
  // cout << "Name: " << this->name << endl;
  std::cout << string(num, dash) << endl << endl;
  std::cout << " Point    : " << this->point << ""<< endl;
 
  std::cout << " Ability  : ";
  this->getAbility().displayAbility();
  std::cout << endl;
  std::cout << " Cards    : ";
  this->bufferCard.first.displayCard();
  std::cout << ", ";
  this->bufferCard.second.displayCard();
  std::cout << endl;
  std::cout << string(num, dash) << endl;
}

void PlayerPoker::PlayerASCII() {
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
  
  std::cout << firstColor; this->getCard(0).displayCard(); cout << secondColor << "    "; this->getCard(1).displayCard(); cout << endl;
        cout << firstColor << "┌─────────┐   " << secondColor << "┌─────────┐    \n";
        cout << firstColor <<"│"<<this->getCard(0).getNum()<< string(1-this->getCard(0).getNum()/10, space)<<"       │   " << secondColor << "│"<< this->getCard(1).getNum() << string(1-this->getCard(1).getNum()/10, space) <<"       │   \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │    \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│    ♣    │   " << secondColor << "│    ♣    │    \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│         │   " << secondColor << "│         │     \n";
        cout << firstColor <<"│       "<<string(1-this->getCard(0).getNum()/10, space)<<this->getCard(0).getNum()<<"│   " << secondColor << "│       "<<string(1-this->getCard(1).getNum()/10, space)<< this->getCard(1).getNum() <<"│     \n";
        cout << firstColor <<"└─────────┘   " << secondColor << "└─────────┘     \n";
}
