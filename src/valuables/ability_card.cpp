#include "ability_card.hpp"

#include <map>
#include <iostream>
using namespace std;

AbilityCard::AbilityCard() {
    this->type = AbilityType::NULLABILITY;
    this->status = true;
    this->killed = false;
}

void AbilityCard::killAbility() {
    this->killed = true;
}

bool AbilityCard::isAbilityKilled() {
    return this->killed;
}

void AbilityCard::giveAbility(AbilityType _type) {
    this->type = _type;
    this->status = true;
    this->killed = false;
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
    if (this->killed) {
        cout << "sudah dimatikan)";
    } else if (this->status) {
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
    return this->type == other.type && this->status == other.status && this->killed == other.killed;
}