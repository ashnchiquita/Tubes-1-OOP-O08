#ifndef PLAYER_CANGKUL_HPP
#define PLAYER_CANGKUL_HPP

#include "player_abc.hpp"
#include <vector>
using namespace std;

class PlayerCangkul : public PlayerABC< vector<Card> > {
  public:
    PlayerCangkul();
    PlayerCangkul(string name, long int x);
    PlayerCangkul(const PlayerCangkul& other);

    Card getCard(int idx);

    PlayerCangkul& operator<<(const Card& card) override;
    PlayerCangkul& operator>>(Card* card) override;

    bool operator<(const PlayerCangkul& other) const;
    void clearCards() override;
    void print() {}
    int getCardCount() const;
};

#endif