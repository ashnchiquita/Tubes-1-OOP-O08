#include "reroll.hpp"

#include <iostream>
using namespace std;

Reroll::Reroll(Game* currentGame) : AbilityCommand(currentGame) {}

Reroll::~Reroll() {}

void Reroll::execute() {
  // Pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua
  cout << this->game->getCurrPlayerRef().getName() << " melakukan REROLL!" << endl;
  // kartu baru
  Card leftCard, rightCard;
  this->game->getDeck() >> &leftCard;
  this->game->getDeck() >> &rightCard;

  // Setting both cards on player
  this->game->getCurrPlayerRef().setCard(0, leftCard);
  this->game->getCurrPlayerRef().setCard(1, rightCard);

  // Interface
  cout << this->game->getCurrPlayerRef().getName() << " melakukan REROLL!" << endl;
  cout << "Melakukan pembuangan kartu yang sedang dimiliki." << endl;
  cout << this->game->getCurrPlayerRef().getName() << " mendapatkan 2 kartu baru yaitu: " << endl;
  cout << "    1. ";
  leftCard.displayCard();
  cout << "    2. ";
  rightCard.displayCard();

  this->turnOffAbility();
}