#include "./game_poker.hpp"
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

GamePoker::GamePoker(): GameABC(7) {
  AbilityType abilityList[7] = {
    AbilityType::REROLL,
    AbilityType::QUADRUPLE,
    AbilityType::QUARTER,
    AbilityType::REVERSE,
    AbilityType::SWAP,
    AbilityType::SWITCH,
    AbilityType::ABILITYLESS,
  };

  Algos r;
  r.iterShuffle(abilityList, 7);

  this->gamePoint = 64;

  for(int i = 0; i < 7; i++) {
    this->playersList.getPlayerAt(i).getAbilityRef().giveAbility(abilityList[i]);
  }
}

long int GamePoker::getGamePoint() const {
  return this->gamePoint;
}

TableCard& GamePoker::getTableCard() {
  return this->mainTable;
}

void GamePoker::resetGame() {
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

  // Randomizer
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
    this->playersList.getPlayerAt(i).getAbilityRef().giveAbility(abilityList[i]);
  } 
  /* DEBUG */
  // this->printGameState();
}

bool GamePoker::isFinished() { return this->playersList.hasWinner(); }

void GamePoker::runGame() {
  do {
    /* DEBUG */
    // printGameState();
    runTurn();
  } while (!this->playersList.isComplete());

  this->givePoint();
}

void GamePoker::printGameState() {
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

void GamePoker::multiplyGamePoint(float multiplier) {
  if (this->gamePoint * multiplier < 1) {
    throw GameMultiplierException();
  } else {
    this->gamePoint = (long int) (this->gamePoint * multiplier);
  }
}

void GamePoker::runTurn() {
  string cmd;
  cout << " --------------------- TABLE CARD ---------------------" << endl;
  this->mainTable.ASCIITable();
  cout << endl << "Sekarang giliran " << this->getCurrPlayerRef().getName() << "!" << endl;
  cout << "\033[1m\033[33m";
  cout << "Game Point : " << this->gamePoint << endl;
  cout << "\033[35m";
  this->getCurrPlayerRef().print();
  cout << " --------------------- PLAYER CARD ---------------------" << endl;
  this->getCurrPlayerRef().PlayerASCII();
  cout << "\033[0m";
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
    catch (CommandHelpException& e){
      command = new Help(this);
      command->execute();
      delete command;
      cout << e.what() << '\n';
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

void GamePoker::givePoint() {
  Combine combi(this->mainTable, this->playersList);
  int winnerIdx = combi.evaluate();
  PlayerPoker& winningPlayer = this->playersList.getPlayerAt(winnerIdx);
  winningPlayer.addPoint(this->gamePoint);
  cout << endl << "Game point sebesar " << this->gamePoint << " diberikan ke " << winningPlayer.getName() << "! Selamat!! >.<" << endl;
  winningPlayer.print();
}

void GamePoker::endGame() {
  cout << "Permainan berakhir" << endl;
  cout << "Leaderboard:" << endl;
  this->playersList.getLeaderboard().printSequencePoints();
  PlayerPoker winner = this->playersList.highestPoint();
  cout << "Pemenangnya adalah " << winner.getName() << "! Selamat!!" << endl;

}