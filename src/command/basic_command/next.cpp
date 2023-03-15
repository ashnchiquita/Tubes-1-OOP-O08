#include "next.hpp"

#include <iostream>
using namespace std;

Next::Next(Game* currentGame) : BasicCommand(currentGame) {}

Next::~Next() {}

void Next::execute() {
    cout << this->game->getCurrPlayerRef().getName() << " melakukan NEXT!" << endl;
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
}