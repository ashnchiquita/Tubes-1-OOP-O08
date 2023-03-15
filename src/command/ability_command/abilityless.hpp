#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "ability_command.hpp"

class Abilityless : public AbilityCommand {
  public:
    Abilityless(Game*);
    void execute();
    ~Abilityless();
};

#endif