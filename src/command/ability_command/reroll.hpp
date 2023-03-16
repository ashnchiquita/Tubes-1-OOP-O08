#ifndef REROLL_HPP
#define REROLL_HPP

#include "ability_command.hpp"

class Reroll : public AbilityCommand {
 public:
  Reroll(GamePoker*);
  void execute();
  ~Reroll();
};

#endif