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

vector<Card> TableCard::getAllCards() {
  return this->bufferCard;
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

void TableCard::clearCards() {
  this->bufferCard.clear();
}

void TableCard::ASCIITable(){
  vector <Card>::iterator it;
  char space =' ';

  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    (it)->displayCard(); cout<< "        ";
  } printf("\n");
  
  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    printf("┌─────────┐    ");
  } printf("\n");

  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    cout << "│"<< (*it).getNum() << string(1-(*it).getNum()/10, space)<<"       │    ";
  } printf("\n");

  for (int i = 0; i<2; i++){
    for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    printf("│         │    ");
    } printf("\n");
  }

  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    printf("│    ♡    │    ");
  } printf("\n");

  for (int i = 0; i<2; i++){
    for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    printf("│         │    ");
    } printf("\n");
  }

  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    cout <<"│       "<<string(1-(*it).getNum()/10, space)<<(*it).getNum()<<"│    ";
  } printf("\n");

  for (it = this->bufferCard.begin(); it != this->bufferCard.end(); ++it){
    if ((*it).getColor() == CardColor::GREEN) {cout << "\033[32m";}
    else if ((*it).getColor() == CardColor::BLUE){ cout << "\033[34m";}
    else if ((*it).getColor() == CardColor::RED){ cout << "\033[31m";}
    else if ((*it).getColor() == CardColor::YELLOW){ cout << "\033[33m";}
    printf("└─────────┘    ");
  } printf("\n");
}