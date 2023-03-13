#include <iostream>
#include "basic_command.hpp"
using namespace std;

BasicCommand::BasicCommand(Game* currentGame) : Command(currentGame) {}
Double::Double(Game* currentGame) : BasicCommand(currentGame) {}
Half::Half(Game* currentGame) : BasicCommand(currentGame) {}
Next::Next(Game* currentGame) : BasicCommand(currentGame) {}

void Double::execute() {
    long int point = this->game->getGamePoint();
    
    cout << "Double" << endl;
    this->game->multiplyGamePoint(2);
    // cout << currGame.getCurrPlayer().name << "melakukan DOUBLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";
}

void Half::execute() {
    long int point = this->game->getGamePoint();

    cout << "Half" << endl;
    // try
    this->game->multiplyGamePoint(0.5);
    // cout << currGame.getCurrPlayer().name << "melakukan HALF!" << endl;

    // catch(err){
    //     cout << "Sayangnya poin hadiah sudah bernilai " << curr.gamePoint << ". Poin hadiah tidak berubah.. Giliran dilanjut!"
    // }
    // cout << "Poin hadiah turun dari " << point << " menjadi curr.gamePoint!";
    
}

void Next::execute() {
    cout << "Next" << endl;
    // cout << "Giliran dilanjut ke pemain selanjutnya."
}