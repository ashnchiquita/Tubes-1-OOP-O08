#include "reverse_direction.hpp"

#include <iostream>
using namespace std;

ReverseDirection::ReverseDirection(Game* currentGame)
    : AbilityCommand(currentGame) {}

ReverseDirection::~ReverseDirection() {}

void ReverseDirection::execute() {
  // Memutar arah giliran eksekusi perintah oleh pemain
  this->game->getPlayersListRef().reversePlayers();
  
  // Interface
  cout << "\033[1m\033[36m \n";
  cout << this->game->getCurrPlayerRef().getName() << " melakukan REVERSE!" << endl;
  cout << "Sisa urutan eksekusi giliran ini: ";
  this->game->getPlayersListRef().getRemainingTurns().printSequence();
  cout << "Urutan eksekusi giliran selanjutnya: ";
  this->game->getPlayersListRef().getNextRound().printSequence();
  cout << "\033[0m";

  this->turnOffAbility();
}