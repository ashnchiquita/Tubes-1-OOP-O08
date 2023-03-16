#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include "ability_command.hpp"

class ReverseDirection : public AbilityCommand {
 public:
  ReverseDirection(GamePoker*);
  void execute();
  ~ReverseDirection();
};

#endif