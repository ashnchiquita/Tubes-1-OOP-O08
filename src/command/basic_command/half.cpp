#include "half.hpp"

#include <iostream>
using namespace std;

Half::Half(Game* currentGame) : BasicCommand(currentGame) {}

Half::~Half() {}

void Half::execute() {
    long int point = this->game->getGamePoint();
    cout << this->game->getCurrPlayerRef().getName() << " melakukan HALF!" << endl;
    this->game->multiplyGamePoint(0.5);
    
    // Interface
    cout << "\033[1m\033[36m \n";
    
    cout << "Poin hadiah turun dari " << point << " menjadi " << this->game->getGamePoint() << endl;
    cout << "\033[0m";
    
}