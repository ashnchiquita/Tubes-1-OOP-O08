#include <iostream>
#include "basic_command.hpp"
using namespace std;

BasicCommand::BasicCommand(Game* currentGame) : Command(currentGame) {}
BasicCommand::~BasicCommand() {}
Double::Double(Game* currentGame) : BasicCommand(currentGame) {}
Double::~Double() {}
Half::Half(Game* currentGame) : BasicCommand(currentGame) {}
Half::~Half() {}
Next::Next(Game* currentGame) : BasicCommand(currentGame) {}
Next::~Next() {}

void Double::execute() {
    long int point = this->game->getGamePoint();
    
    cout << "Double" << endl;
    this->game->multiplyGamePoint(2);
    // Interface
    cout << "Poin hadiah naik dari " << point << " menjadi " << this->game->getGamePoint() << endl;
}

void Half::execute() {
    long int point = this->game->getGamePoint();

    cout << "Half" << endl;
    this->game->multiplyGamePoint(0.5);
    // Interface
    cout << "Poin hadiah turun dari " << point << " menjadi " << this->game->getGamePoint() << endl;
}

void Next::execute() {
    cout << "Next" << endl;
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
}