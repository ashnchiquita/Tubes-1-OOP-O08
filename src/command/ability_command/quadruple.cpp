#include "quadruple.hpp"

#include <iostream>
using namespace std;

Quadruple::Quadruple(Game* currentGame) : AbilityCommand(currentGame) {}

Quadruple::~Quadruple(){}

void Quadruple::execute() {
  // Pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali
  // lipat
  long int point = this->game->getGamePoint();
  this->game->multiplyGamePoint(4);

  // cout << "Quadruple" << endl;
  // Interface
  cout << "\033[1m\033[36m \n";
  cout << this->game->getCurrPlayerRef().getName() << " melakukan QUADRUPLE!" << endl;
  cout << "Poin hadiah naik dari " << point << " menjadi "
       << this->game->getGamePoint() << "!\n";
  cout << "\033[0m";

  this->turnOffAbility();
}