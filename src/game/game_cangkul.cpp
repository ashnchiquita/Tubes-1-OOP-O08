#include "./game_cangkul.hpp"

GameCangkul::GameCangkul(): GameABC<PlayerCangkul>(4) {
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
  return false;
}

void GameCangkul::removeCardAt(int cardIdx, int playerIdx) {
  vector<Card> tempVect;
  PlayerCangkul& player = this->playersList.getPlayerAt(playerIdx);

  for(int i = 0; i < player.getCardCount(); i++) {
    if(player.getCardCount() - 1 - i != cardIdx) {
      Card tempCard;
      player >> &tempCard;
      tempVect.push_back(tempCard);
    }
  }

  for(int i = 0; i < player.getCardCount()-1; i++) {
    Card tempCard = tempVect.back();
    tempVect.pop_back();
    player << tempCard;
  }
}

void GameCangkul::runGame() {
  int maxPlayerIdx = 0;
  Deck tempDeck = this->mainDeck;

  do {
    int input;
    Card card;

    cout << "Pilih kartu:\n";
    for(int i = 0; i < this->playersList.getPlayerAt(maxPlayerIdx).getCardCount(); i++) {
      cout << i+1 << ". ";
      this->playersList.getPlayerAt(maxPlayerIdx).getCard(i).displayCard();
    }
    cin >> input;

    tempDeck << this->playersList.getPlayerAt(maxPlayerIdx).getCard(input);
    this->removeCardAt(input, maxPlayerIdx);

    int nextPlayerIdx = (maxPlayerIdx + 1) % playersList.getSize();
    for(int i = 0; i < 3; i++) {
      cout << "Pilih aksi:\n";
      cout << "1. Ambil kartu\n";
      cout << "2. Buang kartu\n";

      cin >> input;

      // if(input == 1) {

      // }
    }

  } while (!this->isFinished());
}

void GameCangkul::printGameState() {}
void GameCangkul::resetGame() {}
