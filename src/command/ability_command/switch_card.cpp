#include "switch_card.hpp"
#include "../../input_handler/input_handler.hpp"

#include <iostream>
using namespace std;

SwitchCard::SwitchCard(GamePoker* currentGame) : AbilityCommand(currentGame) {}

SwitchCard::~SwitchCard(){}

void SwitchCard::execute() {
  // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik
  // pemain lain
  cout << "\033[1m\033[36m \n";
  cout << this->game->getCurrPlayerRef().getName() << " melakukan SWITCH!" << endl;

  PlayersList<PlayerPoker> optionList;
  int option;
  PlayerPoker& currPlayer = this->game->getCurrPlayerRef();

  Card firstCard, secondCard;
  firstCard = currPlayer.getCard(0);
  secondCard = currPlayer.getCard(1);


  cout << "Kartumu sekarang adalah:" << endl;
  cout << "1. "; firstCard.displayCard(); cout << endl;
  cout << "2. "; secondCard.displayCard(); cout << endl;

  // Picking Options
  bool valid = false;
  do {
    try {
      cout << "Silahkan pilih pemain yang kartunya ingin ditukar: " << endl;
      optionList =
          this->game->getPlayersList() - this->game->getCurrPlayerRef();
      optionList.printSequenceOrder();

      InputHandler<int> optionHandler;
      optionHandler.setInput("> ", 1, optionList.getSize() );
      option = optionHandler.getInput() - 1;

      valid = true;
    } catch (Exception& e) {
      cout << e.what() << endl;
    }
  } while (!valid);

  // Swapping Cards
  PlayerPoker& targetPlayer = 
    this->game->getPlayersListRef().findPlayer(optionList.getPlayerAt(option));
    
  Card tempCard1, tempCard2;
  tempCard1 = targetPlayer.getCard(0);
  tempCard2 = targetPlayer.getCard(1);

  targetPlayer.setCard(0, firstCard);
  targetPlayer.setCard(1, secondCard);
  currPlayer.setCard(0, tempCard1);
  currPlayer.setCard(1, tempCard2);

  // Interface
  cout << "Kedua kartu " << currPlayer.getName() << " telah ditukar dengan "
       << targetPlayer.getName() << "!" << endl;
  cout << "Kartumu sekarang:" << endl;
  this->game->getCurrPlayerRef().getCard(0).displayCard();
  cout << " & ";
  this->game->getCurrPlayerRef().getCard(1).displayCard();
  cout << endl;
  cout << "\033[0m";

  this->turnOffAbility();
}