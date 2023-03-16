#include "./game_cangkul.hpp"
#include "../input_handler/input_handler.hpp"

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
  InputHandler<int> optionHandler;
  int maxNum = 0;
  int maxPlayerIdx = 0;
  Deck tempDeck = this->mainDeck;

  do {
    int input;
    Card card;

    cout << "Kartumu\n";
    for(int i = 0; i < this->playersList.getPlayerAt(maxPlayerIdx).getCardCount(); i++) {
      cout << i+1 << ". ";
      this->playersList.getPlayerAt(maxPlayerIdx).getCard(i).displayCard();
    }
    cin >> input;

    maxNum = this->playersList.getPlayerAt(maxPlayerIdx).getCard(input).getNum();
    tempDeck << this->playersList.getPlayerAt(maxPlayerIdx).getCard(input);
    this->removeCardAt(input, maxPlayerIdx);

    int currPlayerIdx = (maxPlayerIdx + 1) % playersList.getSize();
    for(int i = 0; i < 3; i++) {
      do {
        cout << "Pilih aksi:\n";
        cout << "1. Ambil kartu\n";
        cout << "2. Buang kartu\n";

        cin >> input;

        Card tempCard;
        if(this->mainDeck.getSize() == 0) {
          while(tempDeck.getSize() != 0); {
            tempDeck >> &tempCard;
            this->mainDeck << tempCard;
          }
        } else {
          this->mainDeck >> &tempCard;
          this->playersList.getPlayerAt(currPlayerIdx) << tempCard;
        }
      } while(input != 2);

      cout << "Pilih kartu:\n";
      for(int i = 0; i < this->playersList.getPlayerAt(currPlayerIdx).getCardCount(); i++) {
        cout << i+1 << ". ";
        this->playersList.getPlayerAt(currPlayerIdx).getCard(i).displayCard();
      }
      cin >> input;

      if(this->playersList.getPlayerAt(currPlayerIdx).getCard(input).getNum() > maxNum) {
        maxNum = this->playersList.getPlayerAt(currPlayerIdx).getCard(input).getNum();
        maxPlayerIdx = currPlayerIdx;
      }
      
      tempDeck << this->playersList.getPlayerAt(maxPlayerIdx).getCard(input);
      this->removeCardAt(input, maxPlayerIdx);

      currPlayerIdx = (currPlayerIdx + 1) % this->playersList.getSize();
    }
  } while (!this->isFinished());
}

void GameCangkul::printGameState() {}
void GameCangkul::resetGame() {}
