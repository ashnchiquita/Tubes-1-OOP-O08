#include "./player_cangkul.hpp"
using namespace std;

PlayerCangkul::PlayerCangkul(): PlayerABC() {}

PlayerCangkul::PlayerCangkul(string name, int x): PlayerABC(name, x) {}

PlayerCangkul::PlayerCangkul(const PlayerCangkul& other) : PlayerABC(other) {
  for(Card c: other.bufferCard) {
    this->bufferCard.push_back(c);
  }
}

Card PlayerCangkul::getCard(int idx) {
  return this->bufferCard[idx];
}

PlayerCangkul& PlayerCangkul::operator<<(const Card& card) {
  this->bufferCard.push_back(card);
}

PlayerCangkul& PlayerCangkul::operator>>(Card* card) {
  if (this->bufferCard.empty()) {
    cout << "Player hand is empty\n";
  } else {
    *card = this->bufferCard[this->bufferCard.size() - 1];
    this->bufferCard.pop_back();
  }

  return *this;
}

bool PlayerCangkul::operator<(const PlayerCangkul& other) const {
  return this->point < other.point;
}

int PlayerCangkul::getCardCount() const {
  return this->bufferCard.size();
}