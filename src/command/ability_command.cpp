#include "ability_command.hpp"

#include <iostream>

#include "../exception/exception.hpp"
#include "../input_handler/input_handler.hpp"
#include "../inventory_holder/player.hpp"
#include "../playerslist/playerslist.hpp"
#include "../valuables/card.hpp"
using namespace std;

/* TODO: set ability -> off
try catch & restoring ability */

AbilityCommand::AbilityCommand(Game* currentGame) : Command(currentGame) {}
AbilityCommand::~AbilityCommand(){}
Reroll::Reroll(Game* currentGame) : AbilityCommand(currentGame) {}
Reroll::~Reroll(){}
Quadruple::Quadruple(Game* currentGame) : AbilityCommand(currentGame) {}
Quadruple::~Quadruple(){}
Quarter::Quarter(Game* currentGame) : AbilityCommand(currentGame) {}
Quarter::~Quarter(){}
ReverseDirection::ReverseDirection(Game* currentGame)
    : AbilityCommand(currentGame) {}
ReverseDirection::~ReverseDirection(){}
SwapCard::SwapCard(Game* currentGame) : AbilityCommand(currentGame) {}
SwapCard::~SwapCard(){}
SwitchCard::SwitchCard(Game* currentGame) : AbilityCommand(currentGame) {}
SwitchCard::~SwitchCard(){}
Abilityless::Abilityless(Game* currentGame) : AbilityCommand(currentGame) {}
Abilityless::~Abilityless() {}

void AbilityCommand::turnOffAbility() {
  this->game->getCurrPlayerRef().setAbilityCardStatus(false);
}

// AMAN
void Reroll::execute() {
  // Pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua
  // kartu baru
  Card leftCard, rightCard;
  this->game->getDeck() >> &leftCard;
  this->game->getDeck() >> &rightCard;
  // Setting both cards on player
  this->game->getCurrPlayerRef().setCard(0, leftCard);
  this->game->getCurrPlayerRef().setCard(1, rightCard);

  // Interface
  cout << "Melakukan pembuangan kartu yang sedang dimiliki." << endl;
  cout << "Kamu mendapatkan 2 kartu baru yaitu: " << endl;
  cout << "1.";
  leftCard.displayCard();
  cout << "2.";
  rightCard.displayCard();

  this->turnOffAbility();
}

// AMAN
void Quadruple::execute() {
  // Pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali
  // lipat
  long int point = this->game->getGamePoint();
  this->game->multiplyGamePoint(4);

  // cout << "Quadruple" << endl;
  // Interface
  cout << "Poin hadiah naik dari " << point << " menjadi "
       << this->game->getGamePoint() << "!";

  this->turnOffAbility();
}

// AMAN
void Quarter::execute() {
  // Pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat
  // nilai awal.
  long int point = this->game->getGamePoint();
  this->game->multiplyGamePoint(0.25);
  // cout << "Quarter" << endl;
  // Interface
  cout << "Poin hadiah turun dari " << point << " menjadi "
       << this->game->getGamePoint() << "!";

  this->turnOffAbility();
}

void SwapCard::execute() {
  // Menukar kartu pemain lain

  PlayersList optionList;
  // Picking Options
  int firstOption, secondOption;
  int firstCard, secondCard;

  bool valid = false;
  do {
    try {
      InputHandler<int> optionHandler;
      // Select First Player
      optionList =
          this->game->getPlayersList() - this->game->getCurrPlayerRef();
      optionList.printSequenceOrder();
      optionHandler.setInput("Masukan pilihan: ", 1, optionList.getSize());
      firstOption = optionHandler.getInput() - 1;

      // Select Second Player
      optionList = this->game->getPlayersList() - this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(firstOption));
      optionList.printSequenceOrder();
      optionHandler.setInput("Masukan pilihan: ", 1, optionList.getSize());
      secondOption = optionHandler.getInput() - 1;

      // Select Cards
      optionHandler.setInput("Masukan pilihan: ", 1, 2);
      firstCard = optionHandler.getInput() - 1;
      optionHandler.setInput("Masukan pilihan: ", 1, 2);
      secondCard = optionHandler.getInput() - 1;

      valid = true;
    } catch (Exception& e) {
      cout << e.what() << '\n';
    }
  } while (!valid);

  Player& firstPlayer = this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(firstOption));
  Player& secondPlayer = this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(secondOption));

  // Swapping Cards
  Card tempCard;
  tempCard = firstPlayer.getCard(firstCard - 1);
  firstPlayer.setCard(firstCard - 1, secondPlayer.getCard(secondCard - 1));
  secondPlayer.setCard(secondCard - 1, tempCard);

  // Interface
  cout << "Kartu " << firstPlayer.getName() << " telah tertukar dengan "
       << secondPlayer.getName() << "." << endl;

  this->turnOffAbility();
}

// AMAN
void ReverseDirection::execute() {
  // Memutar arah giliran eksekusi perintah oleh pemain
  this->game->getPlayersListRef().reversePlayers();
  // Interface
  cout << "Sisa urutan eksekusi giliran ini: ";
  this->game->getPlayersListRef().getRemainingTurns().printSequence();
  cout << "Urutan eksekusi giliran berikutnya: ";
  this->game->getPlayersListRef().getNextRound().printSequence();

  this->turnOffAbility();
}

void SwitchCard::execute() {
  // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik
  // pemain lain

  PlayersList optionList;
  int option;
  Player& currPlayer = this->game->getCurrPlayerRef();

  Card firstCard, secondCard;
  firstCard = currPlayer.getCard(0);
  secondCard = currPlayer.getCard(1);

  cout << "Kartumu sekarang adalah:" << endl;
  firstCard.displayCard();
  secondCard.displayCard();

  // Picking Options
  bool valid = false;
  do {
    try {
      cout << "Silahkan pilih pemain yang kartunya ingin Anda tukar" << endl;
      optionList =
          this->game->getPlayersList() - this->game->getCurrPlayerRef();
      optionList.printSequenceOrder();

      InputHandler<int> optionHandler;
      optionHandler.setInput("Masukan pilihan: ", 1, optionList.getSize());
      option = optionHandler.getInput() - 1;

      valid = true;
    } catch (Exception& e) {
      cout << e.what() << '\n';
    }
  } while (!valid);

  // Swapping Cards
  Player& targetPlayer = 
    this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(option));
  targetPlayer.setCard(0, firstCard);
  targetPlayer.setCard(1, secondCard);
  currPlayer.setCard(0, targetPlayer.getCard(0));
  currPlayer.setCard(1, targetPlayer.getCard(1));

  // Interface
  cout << "Kedua kartu " << currPlayer.getName() << " telah ditukar dengan "
       << targetPlayer.getName() << "!" << endl;
  cout << "Kartumu sekarang adalah:" << endl;
  currPlayer.getCard(0).displayCard();
  currPlayer.getCard(1).displayCard();

  this->turnOffAbility();
}

void Abilityless::execute() {
  // Mematikan kemampuan lawan

  PlayersList optionList;
  // Picking Options
  int option;
  cout << this->game->getCurrPlayerRef().getName()
       << " akan mematikan kartu ability lawan!" << endl;

  bool valid = false;
  do {
    try {
      cout << "Silahkan pilih pemain yang kartunya ingin dimatikan" << endl;
      optionList =
          this->game->getPlayersList() - this->game->getCurrPlayerRef();
      optionList.printSequenceOrder();

      InputHandler<int> optionHandler;
      optionHandler.setInput("Masukan pilihan: ", 1, optionList.getSize());

      option = optionHandler.getInput() - 1;

      valid = true;
    } catch (Exception& e) {
      cout << e.what() << '\n';
    }
  } while (!valid);

  Player& targetPlayer = this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(option));

  if (!targetPlayer.getAbilityCardStatus()) {
    cout << "Kartu ability " << targetPlayer.getName()
         << "telah dipakai sebelumnya." << endl;
    cout << "Yah, sayang penggunaan kartu ini sia-sia." << endl;
  } else {
    // Set Ability Nonactive
    targetPlayer.setAbilityCardStatus(false);
    cout << "Kartu ability " << targetPlayer.getName() << "telah dimatikan."
         << endl;
  }

  this->turnOffAbility();
}