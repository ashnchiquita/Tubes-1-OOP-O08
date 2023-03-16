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
#include "../command/basic_command/help.hpp"
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
#include "../algorithm/algos.hpp"
#include "../valuables/card.hpp"
#include "../valuables/combo.hpp"
#include "../input_handler/file_handler.hpp"
#include "../valuables/combine.hpp"

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
  
  // Algos
  Algos r;
  r.iterShuffle(abilityList, 7);

  // Opening /* TODO: ASCII ART */
  cout << "\033[34m" << "                                ~ , ` - . `* Welcome To *' - . `. ~" << "\033[0m" << endl;

  cout << "\033[33m" << "_______________________________________________________________________________________________"<< endl;
  cout << "|                                                                                              |"<< endl;
  cout << "|    ♡♡♡♡♡♡\\   ♡♡♡♡♡♡\\  ♡♡♡♡♡♡♡\\ ♡♡♡♡♡♡\\ ♡♡\\   ♡♡\\       ♡♡♡♡♡♡\\ ♡♡♡♡♡♡♡\\ ♡♡♡♡♡♡\\ ♡♡\\   ♡♡\\    |" << endl;
  cout << "|   ♡♡  __♡♡\\ ♡♡  __♡♡\\ ♡♡  __ ♡♡\\_♡♡  _|♡♡♡\\  ♡♡ |      \\_♡♡  _|♡♡  __ ♡♡\\_♡♡  _|♡♡♡\\  ♡♡ |   |" << endl;
  cout << "|   ♡♡ /  ♡♡ |♡♡ /  ♡♡ |♡♡ |  ♡♡ | ♡♡ |  ♡♡♡♡\\ ♡♡ |        ♡♡ |  ♡♡ |  ♡♡ | ♡♡ |  ♡♡♡♡\\ ♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡♡♡♡♡♡  | ♡♡ |  ♡♡ ♡♡\\♡♡ |        ♡♡ |  ♡♡♡♡♡♡♡  | ♡♡ |  ♡♡ ♡♡\\♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡  ____/  ♡♡ |  ♡♡ \\♡♡♡♡ |        ♡♡ |  ♡♡  ____/  ♡♡ |  ♡♡ \\♡♡♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡ |       ♡♡ |  ♡♡ |\\♡♡♡ |        ♡♡ |  ♡♡ |       ♡♡ |  ♡♡ |\\♡♡♡ |   |" << endl;
  cout << "|    ♡♡♡♡♡♡  | ♡♡♡♡♡♡  |♡♡ |     ♡♡♡♡♡♡\\ ♡♡ | \\♡♡ |      ♡♡♡♡♡♡\\ ♡♡ |     ♡♡♡♡♡♡\\ ♡♡ | \\♡♡ |   |"   << endl;
  cout << "|    \\______/  \\______/ \\__|     \\______|\\__|  \\__|      \\______|\\__|    \\______|\\__|   \\__|   |" << endl;
  cout << "|                                                                                              |"<< endl;
  cout << "|______________________________________________________________________________________________" << "|"<< endl << endl;
  // kata akumah pake foto upin ipin oleng
  
  cout << "\033[34m" << "                         Created by group * ~ ' . * ♡ OOPin 1pin ♡ * . ' ~ * (Kode O08)" << "\033[0m" << endl << endl;

  // Input Source
  CommandHandler<string> optionPicker;
  bool valid = false;
  
  do {
    try {
      cout << "\033[35m";
      optionPicker.yesNoCommand("\nApakah ingin memasukkan konfigurasi deck dari file? [y/n] ");
      cout << "\033[0m";
      string choice = optionPicker.getInput();

      if (choice == "y" || choice == "Y") {
        // Filename
        cout << endl  << "___________________________________________________________" << endl;
        cout          << "| Pastikan file konfigurasi deck berada di folder config. |" << endl;
        cout          << "|_________________________________________________________|" << endl;
        cout << endl << "Masukkan nama file: " << endl << "> ";
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
    cout << endl;
    do {
      cout << "Masukkan nama pemain " << (i + 1) << ": " << endl << "> ";
      getline(cin, name);
    } while (name == "");
    

    // Players get Cards
    this->playersList.addPlayer(Player(name, 0));
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;

    // Players get Ability
    this->playersList.getPlayerAt(i).getAbilityRef().giveAbility(abilityList[i]);
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
  cout << "\n--------------------- TABLE CARD ---------------------" << endl;
  // mainDeck.print();
  this->mainTable.ASCIITable();
  cout << "\033[1m\033[33m";
  cout << endl << "Sekarang giliran " << this->getCurrPlayerRef().getName() << "!" << endl;
  cout << "Game Point : " << this->gamePoint << endl;
  cout << "\033[35m";
  this->getCurrPlayerRef().print();
  cout << "\033[0m";
  cout << " \n\n--------------------- PLAYER CARD ---------------------" << endl;
  this->getCurrPlayerRef().PlayerASCII();
  cout << "\033[0m";
  cout << " \n\n-------------------------------------------------------" << endl;
  
  /* DEBUG */
  // cout << "Kartu ability " << this->getCurrPlayerRef().getName() << ": ";
  // this->getCurrPlayerRef().getAbility().displayAbility();

  Command* command;
  CommandHandler<string> optionHandler;
  bool valid = false;
  do {
    try {
      bool constraints[3] = {!this->playersList.restrictCommand(), this->getCurrPlayerRef().getAbility().getAbilityCardStatus(), this->getCurrPlayerRef().getAbility().isAbilityKilled()};
      optionHandler.turnCommand("\nMasukkan command\n> ", constraints, this->getCurrPlayerRef().getAbility().abilityString());
      cmd = optionHandler.getInput();
      valid = true;
    }
    catch (CommandCardUsedException& e){
      cout << e.what() << '\n';
      cmd = "NEXT";
      valid = true;
    }
    catch (Exception& e) {
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
  } else if (cmd == string("SWAPCARD")) {
    command = new SwapCard(this);
  } else if (cmd == string("SWITCH")) {
    command = new SwitchCard(this);
  } else if (cmd == string("ABILITYLESS")) {
    command = new Abilityless(this);
  } else if (cmd == string("HELP")) {
    command = new Help(this);
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
    /* DEBUG */
    printGameState();
    runTurn();
  } while (!this->playersList.isComplete());
  this->givePoint();
}

void Game::resetGame() {
  cout << endl << "Game di-reset..." << endl << endl;
  this->playersList.reset();
  this->gamePoint = 64;
  // Table Card Reset
  this->mainTable.clearCards();
  // Player Reset
  this->playersList.resetPlayersCards();
  // Deck Reset
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

  // Algos
  Algos r;
  r.iterShuffle(abilityList, 7);

  bool valid = false;
  do {
    try {
      optionPicker.yesNoCommand("\nApakah ingin memasukkan konfigurasi deck dari file? [y/n] ");
      string choice = optionPicker.getInput();

      if (choice == "y" || choice == "Y"){
        // Filename
        /* TODO: sinkronin sama yang di at*/
        cout << endl << "Pastikan file konfigurasi deck berada di folder config." << endl;
        cout << endl << "Masukkan nama file: ";
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
    this->playersList.getPlayerAt(i).getAbilityRef().giveAbility(abilityList[i]);
  } 
  /* DEBUG */
  this->printGameState();
}

bool Game::isFinished() { return this->playersList.hasWinner(); }

void Game::givePoint() {
  Combine combi(this->mainTable, this->playersList);
  int winnerIdx = combi.evaluate();
  Player& winningPlayer = this->playersList.getPlayerAt(winnerIdx);
  winningPlayer.addPoint(this->gamePoint);
  cout << endl << "Game point sebesar " << this->gamePoint << " diberikan ke " << winningPlayer.getName() << "! Selamat!! >.<" << endl;
  winningPlayer.print();
}

void Game::printGameState() {
  char space = ' ';
  char dash = '-';
  int num = 60;
  cout << string(num, dash) << endl;
  cout << "|" << string(num/2-6, space) << "GAME STATE" << string(num/2-6, space) << "|"<< endl;
  cout << "|"<< string(num-2, space) <<"|" << endl;
  cout << "| Game Point : " << this->gamePoint << endl;
  this->playersList.print();
  cout << "| Deck cards count : " << this->mainDeck.getSize() << endl;
  cout << "| ";
  this->mainTable.print();
  cout << string(num, dash) << endl;
}