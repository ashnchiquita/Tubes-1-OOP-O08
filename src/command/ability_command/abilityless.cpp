#include "abilityless.hpp"
#include "../../playerslist/playerslist.hpp"
#include "../../input_handler/input_handler.hpp"

#include <iostream>
using namespace std;

Abilityless::Abilityless(Game* currentGame) : AbilityCommand(currentGame) {}

Abilityless::~Abilityless() {}

void Abilityless::execute() {
  // Mematikan kemampuan lawan
  cout << this->game->getCurrPlayerRef().getName() << " melakukan ABILITYLESS!" << endl;

  if (!this->game->getPlayersList().hasAbility()) {
    cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia :(" << endl;
  } else {
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
          << " telah dipakai sebelumnya." << endl;
      cout << "Yah, sayang penggunaan kartu ini sia-sia." << endl;
    } else {
      // Set Ability Nonactive
      targetPlayer.setAbilityCardStatus(false);
      cout << "Kartu ability " << targetPlayer.getName() << " telah dimatikan."
          << endl;
    }
  }
  
  this->turnOffAbility();
}