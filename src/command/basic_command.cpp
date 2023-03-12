#include <iostream>
#include "basic_command.hpp"
using namespace std;

void Double::execute(Game& currGame) {
    long int point = currGame.getGamePoint();
    
    cout << "Double" << endl;
    currGame.multiplyGamePoint(2);
    // cout << currGame.getCurrPlayer().name << "melakukan DOUBLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";
}

void Half::execute(Game& currGame) {
    long int point = currGame.getGamePoint();

    cout << "Half" << endl;
    // try
    currGame.multiplyGamePoint(0.5);
    // cout << currGame.getCurrPlayer().name << "melakukan HALF!" << endl;

    // catch(err){
    //     cout << "Sayangnya poin hadiah sudah bernilai " << curr.gamePoint << ". Poin hadiah tidak berubah.. Giliran dilanjut!"
    // }
    // cout << "Poin hadiah turun dari " << point << " menjadi curr.gamePoint!";
    
}

void Next::execute(Game& currGame) {
    cout << "Next" << endl;
    // cout << "Giliran dilanjut ke pemain selanjutnya."
}