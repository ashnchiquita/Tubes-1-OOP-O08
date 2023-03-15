#include "swap_card.hpp"
#include "../../input_handler/input_handler.hpp"
#include "../../playerslist/playerslist.hpp"

#include <iostream>
using namespace std;

SwapCard::SwapCard(Game* currentGame) : AbilityCommand(currentGame) {}

SwapCard::~SwapCard(){}

void SwapCard::execute() {
  // Menukar kartu pemain lain

  PlayersList optionList, optionList2;
  // Picking Options
  int firstOption, secondOption;
  int firstCard, secondCard;

  bool valid = false;
  do {
    try {
      InputHandler<int> optionHandler;
      // Select First Player
      cout << "Silakan pilih pemain yang kartunya ingin ditukar: " << endl;
      optionList = this->game->getPlayersList() - this->game->getCurrPlayerRef();
      optionList.printSequenceOrder();
      optionHandler.setInput("> ", 1, optionList.getSize());
      firstOption = optionHandler.getInput() - 1;

      // Select Second Player
      cout << "Silakan pilih pemain yang kartunya ingin ditukar: " << endl;
      optionList2 = optionList - this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(firstOption));
      optionList2.printSequenceOrder();
      optionHandler.setInput("> ", 0, optionList2.getSize());
      secondOption = optionHandler.getInput() - 1;

      Player& secondPlayer = this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(secondOption));
      
      // Select Cards
      optionHandler.setInput("Pilihan kartu pertama: \n 1. Kanan\n 2. Kiri\n> ", 1, 2);
      firstCard = optionHandler.getInput() - 1;
      optionHandler.setInput("Pilihan kartu kedua: \n 1. Kanan\n 2. Kiri\n> ", 1, 2);
      secondCard = optionHandler.getInput() - 1;

      valid = true;
    } catch (Exception& e) {
      cout << e.what() << '\n';
    }

    catch(const exception& e){
      cout << e.what() << '\n';
    }
  } while (!valid);

  Player& firstPlayer = this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(firstOption));
  Player& secondPlayer = this->game->getPlayersListRef().findPlayer(optionList2.getPlayerAt(secondOption));

  // Swapping Cards
  Card tempCard;
  tempCard = firstPlayer.getCard(firstCard - 1);
  firstPlayer.setCard(firstCard - 1, secondPlayer.getCard(secondCard - 1));
  firstPlayer.setCard(secondCard - 1, tempCard);
  
  // Interface
  cout << this->game->getCurrPlayerRef().getName() << " melakukan SWAPCARD!" << endl;
  cout << "Kartu " << firstPlayer.getName() << " telah tertukar dengan "
       << secondPlayer.getName() << "." << endl;

  this->turnOffAbility();
}