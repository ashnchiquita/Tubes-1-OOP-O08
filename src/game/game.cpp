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

    Command * command;
    if (cmd == string("DOUBLE")) {
        command = new Double();
    } else if (cmd == string("HALF")) {
        command = new Half();
    } else if (cmd == string("NEXT")) {
        command = new Next();
    } else if (cmd == string("REROLL")) {
        command = new Reroll();
    } else if (cmd == string("QUADRUPLE")) {
        command = new Quadruple();
    } else if (cmd == string("REVERSE")) {
        command = new ReverseDirection();
    } else if (cmd == string("SWAP")) {
        command = new SwapCard();
    } else if (cmd == string("SWITCH")) {
        command = new SwitchCard();
    } else if (cmd == string("ABILITYLESS")) {
        command = new Abilityless();
    } 
    
    command->execute(*this);
    this->playersList.changeTurn();
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
    if (this->turnCountInARound == 0) {
        this->roundCount++;
        this->playersList.changeTurn();
    }
}

void Game::runGame() {
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