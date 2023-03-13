#include <string>
#include <iostream>
#include <vector>
#include "game.hpp"
#include "../exception/game_exception.hpp"
#include "../command/command.hpp"
#include "../command/basic_command.hpp"
#include "../command/ability_command.hpp"
#include "../input_handler/input_handler.hpp"

using namespace std;

Game::Game() {
    string name;
    cout << "halo selamat dtg" << endl;
    this->roundCount = 0;
    this->turnCountInARound = 0;
    this->gamePoint = 64;
    for (int i = 0; i < 7; i++) {
        getline(cin, name);
        this->playersList.addPlayer(Player(name, 0));
    }
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

Deck& Game::getDeck() {
    return this->mainDeck;
}

TableCard& Game::getTableCard() {
    return this->mainTable;
}

void Game::multiplyGamePoint(float multiplier) {
    if (this->gamePoint * multiplier < 1) {
        throw(GameMultiplierException());
    } else {
        this->gamePoint = (long int) (this->gamePoint * multiplier);
    }
}

void Game::runTurn() {
    string cmd;
    string validCmd[9] = {"DOUBLE", "HALF", "NEXT", "REROLL", "QUADRUPLE", "REVERSE", "SWAP", "SWTIC" "ABILITYLESS"};
    cout << "It's " << this->getCurrPlayerRef().getName() << "'s turn!" << endl;
    
    bool valid = 0;
    do
    {
        try
        {
            InputHandler<string> commandHandler;
            commandHandler.setInput("Insert command: ", validCmd, 9);
            cmd = commandHandler.getInput();
        }
        catch(Exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    } while (!valid);
    
    
    cout << getCurrPlayerRef().getName() << "melakukan " << cmd << "!" << endl;

    Command * command;
    if (cmd == string("DOUBLE")) {
        command = new Double(this);
    } else if (cmd == string("HALF")) {
        command = new Half(this);
    } else if (cmd == string("NEXT")) {
        command = new Next(this);
    } else if (cmd == string("REROLL")) {
        command = new Reroll(this);
    } else if (cmd == string("QUADRUPLE")) {
        command = new Quadruple(this);
    } else if (cmd == string("REVERSE")) {
        command = new ReverseDirection(this);
    } else if (cmd == string("SWAP")) {
        command = new SwapCard(this);
    } else if (cmd == string("SWITCH")) {
        command = new SwitchCard(this);
    } else if (cmd == string("ABILITYLESS")) {
        command = new Abilityless(this);
    }

    command->execute();

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

void Game::endGame() {
    
//     ().addPoint(this->gamePoint);
//     cout << "the winner is" << endl;
//     (*this->playersList.highCard()).print();
}

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
