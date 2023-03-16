#include "help.hpp"

#include <iostream>
using namespace std;

Help::Help(GamePoker* currentGame) : BasicCommand(currentGame) {}

Help::~Help() {}

void Help::execute() {
    // Interface
    cout << "\033[1m\033[36m \n";
    cout << "HELP COMMAND" << endl;
    cout << "\033[0m";

    this->game->runTurn();
    this->game->getPlayersListRef().undoChangeTurn();
}