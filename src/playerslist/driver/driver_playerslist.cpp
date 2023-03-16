#include <iostream>
#include <math.h>
#include "../playerslist.hpp"

int main() {
    PlayersList p;
    string nama;
    // Check input
    for (int i = 0; i < 7; i++) {
        cin >> nama;
        p.addPlayer(Player(nama, pow(2, 30 + i)));
    }

    cout << "==================== BASED p INPUT ====================" << endl;
    p.print();
    cout << endl << endl;

    // ccon
    PlayersList copy = p;

    // change turn
    // tc = 0
    p.changeTurn();
    // tc = 1
    p.changeTurn();
    p.changeTurn();
    p.changeTurn();
    p.changeTurn();
    p.changeTurn();
    p.changeTurn();
    
    // tc = 2
    cout << "==================== CHANGE p TURN ====================" << endl;
    p.print();
    cout << endl << endl;

    cout << "==================== UNDO CHANGE p TURN ====================" << endl;
    p.undoChangeTurn();
    p.print();
    cout << endl << endl;

    // remaining turns
    cout << "==================== p REMAINING TURNS ====================" << endl;
    p.getRemainingTurns().print();
    cout << endl << endl;

    // get next round
    cout << "==================== p NEXT ROUND ====================" << endl;
    p.getNextRound().print();
    cout << endl << endl;

    copy.changeTurn(); // 0
    // copy.changeTurn(); // 1
    // copy.changeTurn(); // 2
    // 3
    
    // di tc ke 3
    cout << "==================== CHANGE copy TURN ====================" << endl;
    copy.print();
    cout << endl << endl;

    // cek reverse
    copy.reversePlayers();
    cout << "==================== REVERSE copy ====================" << endl;
    copy.print();
    cout << endl << endl;

    cout << "==================== copy REMAINING TURNS ====================" << endl;
    copy.getRemainingTurns().print();
    cout << endl << endl;
    
    cout << "==================== copy NEXT ROUND ====================" << endl;
    copy.getNextRound().print();
    cout << endl << endl;

    cout << "==================== copy WINNER FINDING ====================" << endl;
    copy.highestPoint().print();
    if (copy.hasWinner()) {
        cout << "Pemenangnya: " << endl;
        copy.highestPoint().print();
    } else {
        cout << "Gada yang menang" << endl;
    }
    
    cout << endl << endl;
    cout << "==================== copy LEADERBOARD ====================" << endl;
    copy.getLeaderboard().printSequencePoints();
    
    cout << "diff" << endl;
    (copy - Player("1",pow(2, 30))).print();
    copy.print();
    return 0;
}

// g++ -o driver ../valuables/card.cpp ../inventory_holder/player.cpp playerslist.cpp driver.cpp