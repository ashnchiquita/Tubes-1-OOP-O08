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

}