#include "next.hpp"

#include <iostream>
using namespace std;

Next::Next(GamePoker* currentGame) : BasicCommand(currentGame) {}

Next::~Next() {}

void Next::execute() {
    cout << "\033[1m\033[36m \n";
    cout << this->game->getCurrPlayerRef().getName() << " melakukan NEXT!" << endl;
    if (!this->game->getPlayersList().isNextComplete()) {
        cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    }
    cout << "\033[0m";
}