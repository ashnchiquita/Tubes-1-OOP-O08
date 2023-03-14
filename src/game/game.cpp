#include "game.hpp"

#include <iostream>
#include <string>

#include "../command/ability_command.hpp"
#include "../command/basic_command.hpp"
#include "../command/command.hpp"
#include "../exception/game_exception.hpp"
#include "../input_handler/input_handler.hpp"
#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/inventory_holder.hpp"
#include "../inventory_holder/player.hpp"
#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"
#include "../valuables/card.hpp"
#include "../valuables/combo.hpp"

using namespace std;

Game::Game() {
  string name;
  string filename;
  Card temp;
  string option[2] = {"y", "n"};
  // Opening
  cout << "p cape aku cok" << endl;

  // Input Source
  InputHandler<string> optionPicker;
  bool valid = false;
  
  do {
    try {
      optionPicker.setInput("Apakah mau input dari file? [y/n]", option, 2);
      string choice = optionPicker.getInput();

      if (choice == "y"){
        // Filename
        cout << "Masukkan filename: ";
        cin << filename;

        // Get mainDeck
        FileIO fileHandler;
        mainDeck = fileHandler.colorCodeFromSentence(filename);
      }
      valid = true;

    } catch(Exception& e) {
      cout << e.what() << endl;
    }
  } while (!valid);

  this->gamePoint = 64;

  for (int i = 0; i < 7; i++) {
    cout << "Enter your name: " << endl;
    getline(cin, name);
    // Players get Cards
    this->playersList.addPlayer(Player(name, 0));
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
  }
}

long int Game::getGamePoint() const { return this->gamePoint; }

Deck& Game::getDeck() { return this->mainDeck; }

TableCard& Game::getTableCard() { return this->mainTable; }

void Game::multiplyGamePoint(float multiplier) {
  if (this->gamePoint * multiplier < 1) {
    throw GameMultiplierException();
  } else {
    this->gamePoint = this->gamePoint * ((long int) multiplier);
  }
}

// TANDANYA CHI

void Game::runTurn() {
  string cmd;
  string validCmd[9] = {"DOUBLE",
                        "HALF",
                        "NEXT",
                        "REROLL",
                        "QUADRUPLE",
                        "REVERSE",
                        "SWAP",
                        "SWTIC"
                        "ABILITYLESS"};

  cout << "It's " << this->getCurrPlayerRef().getName() << "'s turn!" << endl;

  bool valid = false;
  do {
    try {
      InputHandler<string> commandHandler;
      commandHandler.setInput("Insert command: ", validCmd, 9);
      cmd = commandHandler.getInput();
    } catch (Exception& e) {
      std::cerr << e.what() << '\n';
    }

  } while (!valid);

  cout << getCurrPlayerRef().getName() << "melakukan " << cmd << "!" << endl;

  Command* command;

  if (cmd == string("DOUBLE")) {
    command = new Double(this);
  } else if (cmd == string("HALF")) {
    command = new Half(this);
  } else if (cmd == string("NEXT")) {
    command = new Next(this);
  } else if (cmd == string("REROLL")) {
    command = new Reroll(this);
  } else if (!this->playersList.restrictCommand()) {
    if (cmd == string("QUADRUPLE")) {
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
  } else {
    // TODO: throw exception untuk yang masukin command ability di ronde 0.
    // tolong cek ya apa dia hrs di loop ap ngga
  }

  command->execute();
  delete command;

  this->playersList.changeTurn();

  /* TODO: add table deck kalo nambah ronde */
}

void Game::runGame() {
  // Deck is shuffled when game started
  this->mainDeck.shuffleDeck();

  do {
    printGameState();
    runTurn();
  } while (!this->playersList.isComplete());
  this->givePoint();
}

void Game::resetGame() {
  cout << "game di reset" << endl;
  this->playersList.reset();
  this->gamePoint = 64;
  /* TODO: Deck configuration */
  this->mainDeck.resetDeck();
  this->mainDeck.shuffleDeck();
}

bool Game::isFinished() { return this->playersList.hasWinner(); }

void Game::givePoint() {
  Card* tableCard = new Card[5];
  Card** playerHands = new Card*[this->playersList.getSize()];
  Card* combinedCards = new Card[5];
  tableCard = this->mainTable.getAllCards();

  for (int i = 0; i < this->playersList.getSize(); i++) {
    playerHands[i] = new Card[2];
    playerHands[i] = this->playersList.getPlayerAt(i).getAllCards();
  }

  // Initialization
  Player& winningPlayer = this->playersList.getPlayerAt(0);
  copy(tableCard, tableCard + 5, combinedCards);

  Combo tempCombo(combinedCards, 5);
  int highestCombo = tempCombo.value();

  Card* maxComboCards = new Card[5];
  copy(combinedCards, combinedCards + 5, maxComboCards);

  // Find a player with the highest combo
  // C(5, 4) * C(2, 1)
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i != j) {
        combinedCards[j] = tableCard[j];
      }
    }

    for (int j = 0; j < this->playersList.getSize(); j++) {
      combinedCards[i] = playerHands[j][0];
      tempCombo = *(new Combo(combinedCards, 5));

      if (tempCombo.value() > highestCombo) {
        highestCombo = tempCombo.value();
        winningPlayer = this->playersList.getPlayerAt(j);
        copy(combinedCards, combinedCards + 5, maxComboCards);
      }

      combinedCards[i] = playerHands[j][1];
      tempCombo = *(new Combo(combinedCards, 5));

      if (tempCombo.value() > highestCombo) {
        highestCombo = tempCombo.value();
        winningPlayer = this->playersList.getPlayerAt(j);
        copy(combinedCards, combinedCards + 5, maxComboCards);
      }
    }
  }

  // C(5, 3) * C(2, 2)
  do {
    for (int i = 0; i < this->playersList.getSize(); i++) {
      copy(playerHands[i], playerHands[0] + 2, combinedCards);
      copy(tableCard, tableCard + 3, combinedCards + 2);

      tempCombo = *(new Combo(combinedCards, 5));

      if (tempCombo.value() > highestCombo) {
        highestCombo = tempCombo.value();
        winningPlayer = this->playersList.getPlayerAt(i);
        copy(combinedCards, combinedCards + 5, maxComboCards);
      }
    }
  } while (next_permutation(tableCard, tableCard + 5));

  winningPlayer.addPoint(this->gamePoint);
  cout << "The winner is ";
  winningPlayer.print();

  cout << "Winning combo: ";
  for (int i = 0; i < 5; i++) {
    maxComboCards[i].displayCard();
  }
}

void Game::printGameState() {
  cout << "Game Point : " << this->gamePoint << endl;
  cout << "Players Queue" << endl;
  this->playersList.print();
}

Player& Game::getCurrPlayerRef() { return this->playersList.getCurrPlayer(); }

PlayersList Game::getPlayersList() { return this->playersList; }

PlayersList& Game::getPlayersListRef() { return this->playersList; }