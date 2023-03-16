#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include "ability_command.hpp"

class SwapCard : public AbilityCommand {
 public:
  SwapCard(GamePoker*);
  void execute();
  ~SwapCard();
};

#endif