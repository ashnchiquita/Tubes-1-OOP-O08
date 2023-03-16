#include "half.hpp"

#include <iostream>
using namespace std;

Half::Half(GamePoker* currentGame) : BasicCommand(currentGame) {}

Half::~Half() {}

void Half::execute() {
    long int point = this->game->getGamePoint();
    this->game->multiplyGamePoint(0.5);
    
    // Interface
    cout << "\033[1m\033[36m \n";
    cout << this->game->getCurrPlayerRef().getName() << " melakukan HALF!" << endl;
    cout << "Poin hadiah turun dari " << point << " menjadi " << this->game->getGamePoint() << endl;
    cout << "\033[0m";
    
}