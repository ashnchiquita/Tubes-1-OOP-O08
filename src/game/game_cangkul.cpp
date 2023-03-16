#include "./game_cangkul.hpp"

GameCangkul::GameCangkul(): GameABC(4) {
  Card temp;

  for(int i = 0; i < 4; i++) {
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
  }
}

bool GameCangkul::isFinished() {
  for(int i = 0; i < 4; i++) {
    if(this->playersList.getPlayerAt(i).getCardCount() == 0) {
      return true;
    }
  }
}

void GameCangkul::runGame() {
  int maxPlayerIdx = 0;
  do {
    bool valid;
    int input;
    
    do {
      cout << "Pilih kartu:\n";
      for(int i = 0; i < this->playersList.getPlayerAt(maxPlayerIdx).getCardCount(); i++) {
        cout << i+1 << ". ";
        this->playersList.getPlayerAt(maxPlayerIdx).getCard(i).displayCard();
      }

    }

  } while (!this->isFinished());
}