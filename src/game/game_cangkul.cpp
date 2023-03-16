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

void GameCangkul::ambilKartu(int currPlayerIdx){
  Card tempCard;
  if(this->mainDeck.getSize() == 0) {
    if(this->tempDeck.getSize() != 0) {
      while(this->tempDeck.getSize() != 0); {
        tempDeck >> &tempCard;
        this->mainDeck << tempCard;
      }
    }
    else{
      cout << "Deck kosong, buang kartu woy!" << endl;
    }
  } else {
    this->mainDeck >> &tempCard;
    this->playersList.getPlayerAt(currPlayerIdx) << tempCard;
  }
}


void GameCangkul::removeCardAt(int cardIdx, int playerIdx) {
  vector<Card> tempVect;
  PlayerCangkul& player = this->playersList.getPlayerAt(playerIdx);

  int n = player.getCardCount();
  for(int i = 0; i < n; i++) {
    if(n - 1 - i != cardIdx) {
      Card tempCard;
      player >> &tempCard;
      tempCard.displayCard();
      cout << '\n';
      tempVect.push_back(tempCard);
    } else {
      Card tempCard;
      player >> &tempCard;
    }
  }

  for(int i = 0; i < n-1; i++) {
    Card tempCard = tempVect.back();
    tempVect.pop_back();
    player << tempCard;
  }
}

void GameCangkul::runGame() {
  this->tempDeck = this->mainDeck;
  
  Card topCard;
  int maxPlayerIdx = 0;
  InputHandler<int> optionHandler;
  bool valid = 0;

  do {
    int input;
    Card card;

    cout << "\nPemain " << this->playersList.getPlayerAt(maxPlayerIdx).getName() << '\n';
    cout << "Kartu yang dimiliki\n";
    for(int i = 0; i < this->playersList.getPlayerAt(maxPlayerIdx).getCardCount(); i++) {
      cout << i+1 << ". ";
      this->playersList.getPlayerAt(maxPlayerIdx).getCard(i).displayCard();
      cout << '\n';
    }

    valid = 0;
    do{
      try{
        optionHandler.setInput("Pilih kartu: ", 1, this->playersList.getPlayerAt(maxPlayerIdx).getCardCount());
        input = optionHandler.getInput() - 1;
        valid = 1;
      } catch(Exception& e){
        cout << e.what() << endl;
      }
    } while(!valid);
    topCard = this->playersList.getPlayerAt(maxPlayerIdx).getCard(input);
    tempDeck << this->playersList.getPlayerAt(maxPlayerIdx).getCard(input);
    this->removeCardAt(input, maxPlayerIdx);

    int currPlayerIdx = (maxPlayerIdx + 1) % playersList.getSize();
    for(int i = 0; i < 3; i++) {
      cout << "\nPemain " << this->playersList.getPlayerAt(currPlayerIdx).getName() << '\n';

      do {
        for(int i = 0; i < this->playersList.getPlayerAt(currPlayerIdx).getCardCount(); i++) {
          cout << i+1 << ". ";
          this->playersList.getPlayerAt(currPlayerIdx).getCard(i).displayCard();
          cout << '\n';
        }
        
        cout << "\nKartu paling tinggi sekarang: "; topCard.displayCard(); cout << endl;
        cout << "Pilih aksi:\n";
        cout << "1. Ambil kartu\n";
        cout << "2. Buang kartu\n";

        valid = 0;
        do{
          try{
            optionHandler.setInput("> ", 1, 2);
            input = optionHandler.getInput();
            valid = 1;
          } catch(Exception& e){
            cout << e.what() << endl;
          }
        } while(!valid);

        if(input == 1) {
          ambilKartu(currPlayerIdx);
        }
      } while(input != 2);

      
      valid = 0;
      do{
        try{
          optionHandler.setInput("Pilih kartu: ", 1, this->playersList.getPlayerAt(currPlayerIdx).getCardCount());
          input = optionHandler.getInput() - 1;
          if(this->playersList.getPlayerAt(currPlayerIdx).getCard(input).getColor() != topCard.getColor()) {
            cout << "Warna kartu tidak valid" << endl;
          } else {
            valid = 1;
          }
        } catch(Exception& e){
          cout << e.what() << endl;
        }
      } while(!valid);

      if(this->playersList.getPlayerAt(currPlayerIdx).getCard(input).getNum() > topCard.getNum()) {
        topCard = this->playersList.getPlayerAt(currPlayerIdx).getCard(input);
        maxPlayerIdx = currPlayerIdx;
      }

      tempDeck << this->playersList.getPlayerAt(currPlayerIdx).getCard(input);
      this->removeCardAt(input, currPlayerIdx);

      currPlayerIdx = (currPlayerIdx + 1) % this->playersList.getSize();
    }


  } while (!this->isFinished());
}

void GameCangkul::printGameState() {}
void GameCangkul::resetGame() {}
