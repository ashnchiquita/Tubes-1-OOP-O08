#include "ability_card.hpp"

#include <map>
#include <iostream>
using namespace std;

AbilityCard::AbilityCard() {
    this->type = AbilityType::NULLABILITY;
    this->status = true;
}

void AbilityCard::killAbility() {
    this->type = AbilityType::NULLABILITY;
    this->status = false;
}

bool AbilityCard::isAbilityKilled() {
    return this->type == AbilityType::NULLABILITY && this->status == false;
}

void AbilityCard::giveAbility(AbilityType _type) {
    this->type = _type;
    this->status = true;
}

bool AbilityCard::getAbilityCardStatus() const {
    return this->status;
}

void AbilityCard::setAbilityCardStatus(bool in) {
    this->status = in;
}

void AbilityCard::useAbility() {
    this->status = false;
}

void AbilityCard::displayAbility() const {
    cout << "Kartu " << this->abilityString() << " (";
    if (this->status) {
        cout << "belum digunakan)";
    } else {
        cout << "sudah digunakan)";
    }
}

string AbilityCard::abilityString() const {
    map<AbilityType, string> typeMap;
    typeMap[AbilityType::REROLL] = "REROLL";
    typeMap[AbilityType::QUADRUPLE] = "QUADRUPLE";
    typeMap[AbilityType::QUARTER] = "QUARTER";
    typeMap[AbilityType::REVERSE] = "REVERSE";
    typeMap[AbilityType::SWAP] = "SWAPCARD";
    typeMap[AbilityType::SWITCH] = "SWITCH";
    typeMap[AbilityType::ABILITYLESS] = "ABILITYLESS";
    typeMap[AbilityType::NULLABILITY] = "NULLABILITY";

    return typeMap[this->type];
}

bool AbilityCard::operator==(const AbilityCard& other) const {
    return this->type == other.type && this->status == other.status;
}