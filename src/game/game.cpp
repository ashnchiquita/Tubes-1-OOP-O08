#include "game.hpp"
#include "../command/command.hpp"
#include "../command/ability_command/ability_command.hpp"
#include "../command/ability_command/abilityless.hpp"
#include "../command/ability_command/quadruple.hpp"
#include "../command/ability_command/quarter.hpp"
#include "../command/ability_command/reroll.hpp"
#include "../command/ability_command/reverse_direction.hpp"
#include "../command/ability_command/swap_card.hpp"
#include "../command/ability_command/switch_card.hpp"
#include "../command/basic_command/basic_command.hpp"
#include "../command/basic_command/double.hpp"
#include "../command/basic_command/half.hpp"
#include "../command/basic_command/next.hpp"
#include "../exception/game_exception.hpp"
#include "../exception/command_exception.hpp"
#include "../valuables/combo.hpp"
#include "../input_handler/command_handler.hpp"
#include "../inventory_holder/deck.hpp"
#include "../inventory_holder/inventory_holder.hpp"
#include "../inventory_holder/player.hpp"
#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"
#include "../randomizer/randomizer.hpp"
#include "../valuables/card.hpp"
#include "../valuables/combo.hpp"
#include "../input_handler/file_handler.hpp"

#include <iostream>
#include <string>
using namespace std;

Game::Game() {
  // Initialization
  string name, filename;
  Card temp;
  AbilityType abilityList[7] = {
    AbilityType::REROLL, 
    AbilityType::QUADRUPLE, 
    AbilityType::QUARTER, 
    AbilityType::REVERSE, 
    AbilityType::SWAP, 
    AbilityType::SWITCH, 
    AbilityType::ABILITYLESS };
  
  // Randomizer
  Randomizer r;
  r.iterShuffle(abilityList, 7);

  // Opening /* TODO: ASCII ART */
  cout << "~ , ` - . `* Welcome To *' - . `. ~" << endl;
  cout << "             A S C I I " << endl;
  cout << "               A R T   " << endl << endl;
  // kata akumah pake foto upin ipin oleng
  cout << "Created by group * ~ ' . * ♡ OOPin 1pin ♡ * . ' ~ * (Kode O08)" << endl << endl;

  // Input Source
  CommandHandler<string> optionPicker;
  bool valid = false;
  
  do {
    try {
      optionPicker.yesNoCommand("\nApakah ingin memasukkan konfigurasi deck dari file? [y/n] ");
      string choice = optionPicker.getInput();

      if (choice == "y" || choice == "Y"){
        // Filename
        cout << endl << "Pastikan file konfigurasi deck berada di folder config." << endl;
        cout << "Masukkan nama file: ";
        cin >> filename;

        // Get mainDeck
        FileHandler fileHandler;
        mainDeck = fileHandler.colorCodeFromSentence(filename);
      }

      valid = true;
    } catch(Exception& e) {
      cout << e.what() << endl;
    }
  } while (!valid);

  this->gamePoint = 64;

  // Config Player
  cin.ignore();

  for (int i = 0; i < 7; i++) {
    // Insert name for players
    cout << "Masukkan nama pemain " << (i + 1) << ": ";
    getline(cin, name);

    // Players get Cards
    this->playersList.addPlayer(Player(name, 0));
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;

    // Players get Ability
    this->playersList.getPlayerAt(i).setAbilityType(abilityList[i]);
  }
}

long int Game::getGamePoint() const { return this->gamePoint; }

Player& Game::getCurrPlayerRef() { return this->playersList.getCurrPlayer(); }

Deck& Game::getDeck() { return this->mainDeck; }

TableCard& Game::getTableCard() { return this->mainTable; }

PlayersList Game::getPlayersList() { return this->playersList; }

PlayersList& Game::getPlayersListRef() { return this->playersList; }

void Game::multiplyGamePoint(float multiplier) {
  if (this->gamePoint * multiplier < 1) {
    throw GameMultiplierException();
  } else {
    this->gamePoint = (long int) (this->gamePoint * multiplier);
  }
}

void Game::runTurn() {
  string cmd;

  cout << endl << "Sekarang giliran " << this->getCurrPlayerRef().getName() << "!" << endl;
  cout << "Kartu ability " << this->getCurrPlayerRef().getName() << ": ";
  this->getCurrPlayerRef().displayAbility();

  Command* command;
  CommandHandler<string> optionHandler;
  bool valid = false;
  do {
    try {
      optionHandler.turnCommand("Masukkan command\n> ", !this->playersList.restrictCommand(), this->getCurrPlayerRef().abilityString());
      cmd = optionHandler.getInput();
      valid = true;
    } catch (Exception& e) {
      cout << e.what() << '\n';
    }

  } while (!valid);

  // Creating command
  if (cmd == string("DOUBLE")) {
    command = new Double(this);
  } else if (cmd == string("HALF")) {
    command = new Half(this);
  } else if (cmd == string("NEXT")) {
    command = new Next(this);
  } else if (cmd == string("QUARTER")) {
    command = new Quarter(this);
  } else if (cmd == string("QUADRUPLE")) {
    command = new Quadruple(this);
  } else if (cmd == string("REROLL")) {
    command = new Reroll(this);
  } else if (cmd == string("REVERSE")) {
    command = new ReverseDirection(this);
  } else if (cmd == string("SWAP")) {
    command = new SwapCard(this);
  } else if (cmd == string("SWITCH")) {
    command = new SwitchCard(this);
  } else if (cmd == string("ABILITYLESS")) {
    command = new Abilityless(this);
  }

  try{
    command->execute();
  } catch (Exception& e){
    cout << e.what() << endl;
  }
  
  delete command;

  this->playersList.changeTurn();
  
  if (this->playersList.isNewRound() && !this->playersList.restrictTable()) {
    Card temp;
    this->mainDeck >> &temp;
    this->mainTable << temp;
  }
}

void Game::runGame() {
  do {
    printGameState();
    runTurn();
  } while (!this->playersList.isComplete());

  this->givePoint();
}

void Game::resetGame() {
  cout << endl << "Game di-reset..." << endl << endl;
  this->playersList.reset();
  this->gamePoint = 64;
  this->mainDeck.resetDeck();
  this->mainDeck.shuffleDeck();

  // Input Source
  CommandHandler<string> optionPicker;
  Card temp;
  string filename;
  AbilityType abilityList[7] = {
    AbilityType::REROLL, 
    AbilityType::QUADRUPLE, 
    AbilityType::QUARTER, 
    AbilityType::REVERSE, 
    AbilityType::SWAP, 
    AbilityType::SWITCH, 
    AbilityType::ABILITYLESS};

  // Randomizer
  Randomizer r;
  r.iterShuffle(abilityList, 7);

  bool valid = false;
  do {
    try {
      optionPicker.yesNoCommand("\nApakah ingin memasukkan konfigurasi deck dari file? [y/n] ");
      string choice = optionPicker.getInput();

      if (choice == "y" || choice == "Y"){
        // Filename
        cout << endl << "Pastikan file konfigurasi deck berada di folder config." << endl;
        cout << "Masukkan nama file: ";
        cin >> filename;

        // Get mainDeck
        FileHandler fileHandler;
        mainDeck = fileHandler.colorCodeFromSentence(filename);
      }
      valid = true;

    } catch(Exception& e) {
      cout << e.what() << endl;
    }
  } while (!valid);

  // Config Player
  for (int i = 0; i < 7; i++) {
    // Players get Cards
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    // Players get Ability
    this->playersList.getPlayerAt(i).setAbilityType(abilityList[i]);
  } 
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

  Combo * tempC;

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
      tempC = new Combo(combinedCards, 5);
      tempCombo = *(tempC);

      if (tempCombo.value() > highestCombo) {
        highestCombo = tempCombo.value();
        winningPlayer = this->playersList.getPlayerAt(j);
        copy(combinedCards, combinedCards + 5, maxComboCards);
      }

      delete tempC;

      combinedCards[i] = playerHands[j][1];
      tempC = new Combo(combinedCards, 5);
      tempCombo = *(tempC);

      if (tempCombo.value() > highestCombo) {
        highestCombo = tempCombo.value();
        winningPlayer = this->playersList.getPlayerAt(j);
        copy(combinedCards, combinedCards + 5, maxComboCards);
      }

      delete tempC;
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
  cout << endl << "Game point sebesar " << this->gamePoint << " diberikan ke " << winningPlayer.getName() << endl;
  winningPlayer.print();

  cout << "Combo " << winningPlayer.getName() << ": " << endl;
  for (int i = 0; i < 5; i++) {
    maxComboCards[i].displayCard();
  }

  for (int i = 0; i < this->playersList.getSize(); i++) {
    delete playerHands[i];
  }

  delete [] playerHands;
  delete [] tableCard;
  delete [] combinedCards;
  delete [] maxComboCards;
}

void Game::printGameState() {
  cout << "============= GAME STATE =============" << endl;
  cout << "Game Point : " << this->gamePoint << endl;
  cout << "Players Queue" << endl;
  this->playersList.print();
  cout << "======================================" << endl;
}