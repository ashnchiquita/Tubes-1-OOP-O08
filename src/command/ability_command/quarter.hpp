#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "ability_command.hpp"

class Quarter : public AbilityCommand {
 public:
  Quarter(Game*);
  void execute();
  ~Quarter();
};

#endif