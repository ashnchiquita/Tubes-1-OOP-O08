#ifndef _ABILITY_CARD_HPP_
#define _ABILITY_CARD_HPP_

#include "valuable.hpp"
using namespace std;


enum class AbilityType { REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS};

class AbilityCard : public Valuable {
private:
    AbilityType type;
    bool active;
public:
    AbilityCard();
    AbilityCard(AbilityType);

    AbilityType getType() const;
    void setType();
    bool getStatus() const;
    void setStatus();

    bool isValidCard() const;
    void displayCard();
    float value();
};

#endif