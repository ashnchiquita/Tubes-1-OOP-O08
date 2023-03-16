#include "reverse_direction.hpp"

#include <iostream>
using namespace std;

ReverseDirection::ReverseDirection(GamePoker* currentGame)
    : AbilityCommand(currentGame) {}

ReverseDirection::~ReverseDirection() {}

void ReverseDirection::execute() {
  // Memutar arah giliran eksekusi perintah oleh pemain
  
  // Interface
  cout << "\033[1m\033[36m \n";
  cout << this->game->getCurrPlayerRef().getName() << " melakukan REVERSE!" << endl;
  this->turnOffAbility();

  this->game->getPlayersListRef().reversePlayers();
  cout << "Sisa urutan eksekusi giliran ini: ";
  this->game->getPlayersListRef().getRemainingTurns().printSequence();
  cout << "Urutan eksekusi giliran selanjutnya: ";
  this->game->getPlayersListRef().getNextRound().printSequence();
  cout << "\033[0m";

  this->game->getPlayersList().print();
  this->game->getPlayersListRef().afterReverse();
  this->game->runTurn();
  this->game->getPlayersListRef().undoChangeTurn();
  this->game->getPlayersListRef().afterReverse();
}