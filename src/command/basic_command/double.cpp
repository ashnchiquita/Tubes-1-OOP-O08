#include "double.hpp"

#include <iostream>
using namespace std;

Double::Double(Game* currentGame) : BasicCommand(currentGame) {}

Double::~Double() {}

void Double::execute() {
    long int point = this->game->getGamePoint();
    this->game->multiplyGamePoint(2);
    
    // Interface
    cout << this->game->getCurrPlayerRef().getName() << " melakukan DOUBLE!" << endl;
    cout << "Poin hadiah naik dari " << point << " menjadi " << this->game->getGamePoint() << endl;
}