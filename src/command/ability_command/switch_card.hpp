#ifndef SWITCH_CARD_HPP
#define SWITCH_CARD_HPP

#include "ability_command.hpp"

class SwitchCard : public AbilityCommand {
 public:
  SwitchCard(GamePoker*);
  void execute();
  ~SwitchCard();
};

#endif