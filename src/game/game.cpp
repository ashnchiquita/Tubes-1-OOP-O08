#include <string>
#include <iostream>
#include <vector>
#include "game.hpp"
#include "../command/command.hpp"
#include "../command/basic_command.hpp"
#include "../command/ability_command.hpp"

using namespace std;

Game::Game() {
    string name;
    int card;
    cout << "halo selamat dtg" << endl;
    this->roundCount = 0;
    this->turnCountInARound = 0;
    this->gamePoint = 64;
    for (int i = 0; i < 7; i++) {
        /* try catch */
        cin >> name >> card;
        this->playersList.addPlayer(Player(name, card));
    }

    /* TODO: Deck initialization */
}

int Game::getRoundCount() {
    return this->roundCount;
}

int Game::getTurnCountInARound() {
    return this->turnCountInARound;
}

long int Game::getGamePoint() {
    return this->gamePoint;
}

void Game::multiplyGamePoint(float multiplier) {
    if (this->gamePoint * multiplier < 1) {
        // TODO: throw exc
    } else {
        this->gamePoint = (long int) (this->gamePoint * multiplier);
    }
}

void Game::runTurn() {
    string cmd;
    cout << "It's " << this->getCurrPlayerRef().getName() << "'s turn!" << endl;
    cout << "Insert command: ";
    /* TODO: try catch */
    cin >> cmd;

    // Command * command;
    // if (cmd == string("DOUBLE")) {
    //     command = new Double();
    // } else if (cmd == string("HALF")) {
    //     command = new Half();
    // } else if (cmd == string("NEXT")) {
    //     command = new Next();
    // } else if (cmd == string("REROLL")) {
    //     command = new Reroll();
    // } else if (cmd == string("QUADRUPLE")) {
    //     command = new Quadruple();
    // } else if (cmd == string("REVERSE")) {
    //     command = new ReverseDirection();
    // } else if (cmd == string("SWAP")) {
    //     command = new SwapCard();
    // } else if (cmd == string("SWITCH")) {
    //     command = new SwitchCard();
    // } else if (cmd == string("ABILITYLESS")) {
    //     command = new Abilityless();
    // } 

    Command * command;
    if (cmd == string("DOUBLE")) {
        this->Double();
    } else if (cmd == string("HALF")) {
        this->Half();
    } else if (cmd == string("NEXT")) {
        this->Next();
    } else if (cmd == string("REROLL")) {
        this->Reroll();
    } else if (cmd == string("QUADRUPLE")) {
        this->Quadruple();
    } else if (cmd == string("REVERSE")) {
        this->ReverseDirection();
    } else if (cmd == string("SWAP")) {
        this->SwapCard();
    } else if (cmd == string("SWITCH")) {
        this->SwitchCard();
    } else if (cmd == string("ABILITYLESS")) {
        this->AbilityLess();
    } 

    this->playersList.changeTurn();
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
    if (this->turnCountInARound == 0) {
        this->roundCount++;
        this->playersList.changeTurn();
    }
}

void Game::runGame() {
    // Deck is shuffled when game started
    this->mainDeck.shuffleDeck();

    do {
        printGameState();
        runTurn();
    } while (!this->isComplete());
    /* TODO: uncomment after implementation */
    // this->endGame();
}

void Game::resetGame() {
    cout << "game di reset" << endl;
    this->roundCount = 0;
    this->turnCountInARound = 0;
    this->gamePoint = 64;
    this->playersList.reset();
    /* TODO: Deck configuration */
    this->mainDeck.resetDeck();
    this->mainDeck.shuffleDeck();
}

bool Game::isComplete() {
    return this->roundCount == 6 && this->turnCountInARound == 0;
}

/* TODO: implement */
// void Game::endGame() {
//     (*this->playersList.highCard()).addPoint(this->gamePoint);
//     cout << "the winner is" << endl;
//     (*this->playersList.highCard()).print();
// }

void Game::printGameState() {
    cout << "Game Point : " << this->gamePoint << endl;
    cout << "Round Count : " << this->roundCount << endl;
    cout << "Turn Count : " << this->turnCountInARound << endl;
    cout << "Players State" << endl;
    this->playersList.print();
}

Player& Game::getCurrPlayerRef() {
    return this->playersList.getCurrPlayer();
}




// ================= COMMANDS ====================
void Game::Double(){
    long int point = getGamePoint();
    this->multiplyGamePoint(2);

    cout << "Double" << endl;
    // cout << getCurrPlayer().name << "melakukan DOUBLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";
}

void Game::Half(){
    long int point = getGamePoint();
    this->multiplyGamePoint(0.5);

    cout << "Half" << endl;
    /* TODO: try catch */
}

void Game::Next(){
    cout << "Next" << endl;
    
}

// ================= ABILITY COMMANDS ====================

void Game::Reroll() {
    // Pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru
    Card leftCard, rightCard;
    mainDeck >> &leftCard;
    mainDeck >> &rightCard;
    // Setting both cards on player
    this->getCurrPlayerRef().setCard(0, leftCard);
    this->getCurrPlayerRef().setCard(1, rightCard);
}

void Game::Quadruple() {
    // Pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali lipat
    long int point = getGamePoint();
    this->multiplyGamePoint(4);

    cout << "Quadruple" << endl;
    // cout << currGame.getCurrPlayer().name << "melakukan QUADRUPLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";

}
void Game::Quarter() {
    // Pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat nilai awal.
    long int point = getGamePoint();
    this->multiplyGamePoint(0.25);

    cout << "Quarter" << endl;
    /* TODO: try catch */
}

void Game::SwapCard() {
    
}

void Game::ReverseDirection() {
    // Memutar arah giliran eksekusi perintah oleh pemain
    this->getPlayersListRef().reversePlayers(getTurnCountInARound());
}

void Game::SwitchCard() {
    // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik pemain lain

}

void Game::AbilityLess() {

}