#include "quarter.hpp"

#include <iostream>
using namespace std;

Quarter::Quarter(GamePoker* currentGame) : AbilityCommand(currentGame) {}

Quarter::~Quarter() {}

void Quarter::execute() {
  // Pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat
  // nilai awal.
  long int point = this->game->getGamePoint();
  this->game->multiplyGamePoint(0.25);

  // Interface
  cout << "\033[1m\033[36m \n";
  cout << this->game->getCurrPlayerRef().getName() << " melakukan QUARTER!" << endl;
  cout << "Poin hadiah turun dari " << point << " menjadi "
       << this->game->getGamePoint() << "!" << endl;
  cout << "\033[0m";

  this->turnOffAbility();
}