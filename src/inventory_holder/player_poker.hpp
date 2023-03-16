#ifndef PLAYER_POKER_HPP
#define PLAYER_POKER_HPP

#include "player_abc.hpp"

class PlayerPoker : public PlayerABC< pair<Card, Card> > {
  protected:
    AbilityCard abilityCard;

  public:
    PlayerPoker();
    PlayerPoker(string name);
    PlayerPoker(string name, long int point);
    PlayerPoker(const PlayerPoker& other);
    // PlayerPoker& operator=(const PlayerPoker& other);

    AbilityCard& getAbilityRef();
    AbilityCard getAbility() const;

    // IDX 0 for LeftCard, IDX 1 for RightCard
    Card getCard(int idx);
    void setCard(int idx, Card card);

    vector<Card> getAllCards() const;

    void clearCards();

    // operator
    PlayerPoker& operator<<(const Card& card) override;
    PlayerPoker& operator>>(Card* card) override;

    void print();
    void PlayerASCII();

    bool operator<(const PlayerPoker& other) const {
  return this->point < other.point;
}
};

#endif