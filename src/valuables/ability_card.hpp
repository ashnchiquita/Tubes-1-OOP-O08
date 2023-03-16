#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include <string>
using namespace std;

enum class AbilityType {
  REROLL,
  QUADRUPLE,
  QUARTER,
  REVERSE,
  SWAP,
  SWITCH,
  ABILITYLESS,
  NULLABILITY
};

class AbilityCard {
  private:
    AbilityType type;
    bool status, killed;
  public:
    AbilityCard();
    void killAbility();
    bool isAbilityKilled();
    void giveAbility(AbilityType);
    bool getAbilityCardStatus() const;
    void setAbilityCardStatus(bool);
    void useAbility();
    void displayAbility() const;
    string abilityString() const;
    bool operator==(const AbilityCard& other) const;
};
#endif 