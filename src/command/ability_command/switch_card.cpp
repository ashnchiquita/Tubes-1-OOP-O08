#include "switch_card.hpp"
#include "../../input_handler/input_handler.hpp"

#include <iostream>
using namespace std;

SwitchCard::SwitchCard(Game* currentGame) : AbilityCommand(currentGame) {}

SwitchCard::~SwitchCard(){}

void SwitchCard::execute() {
  // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik
  // pemain lain
  cout << this->game->getCurrPlayerRef().getName() << " melakukan SWITCHCARD!" << endl;

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
      optionHandler.setInput("Masukan pilihan: ", 1, optionList.getSize() );
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