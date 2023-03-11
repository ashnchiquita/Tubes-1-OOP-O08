#include <string>
#include <iostream>
#include <vector>
#include "game_draft.hpp"
using namespace std;

#include "command.hpp"

Game::Game() {
    string name;
    int card;
    cout << "halo selamat dtg" << endl;
    this->roundCount = 0;
    this->turnCountInARound = 0;
    this->gamePoint = 64;
    for (int i = 0; i < 7; i++) {
        cin >> name >> card;
        this->pl.addPlayer(Player(name, card));
    }
}

void Game::addRound() {
    this->roundCount++;
}

void Game::runTurn() {
    int cmd;
    cout << "It's " << this->pl.pq.front().name << "'s turn!" << endl;
    cout << "Insert command: ";
    cin >> cmd;
    Command com = Command(cmd);
    com.execute(*this);
    this->pl.changeTurn();
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
    if (this->turnCountInARound == 0) {
        addRound();
        this->pl.changeTurn();
    }
}

void Game::runGame() {
    do {
        printGameState();
        runTurn();
    } while (!this->isFinished());
    this->endGame();
}

bool Game::isFinished() {
    return this->roundCount == 6 && this->turnCountInARound == 0;
}

void Game::endGame() {
    (*this->pl.highCard()).addPoint(this->gamePoint);
    cout << "the winner is" << endl;
    (*this->pl.highCard()).print();
}

void Game::printGameState() {
    cout << "Game Point : " << this->gamePoint << endl;
    cout << "Round Count : " << this->roundCount << endl;
    cout << "Turn Count : " << this->turnCountInARound << endl;
    cout << "Players State" << endl;
    this->pl.print();
}