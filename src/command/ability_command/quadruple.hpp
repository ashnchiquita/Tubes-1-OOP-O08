#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "ability_command.hpp"

class Quadruple : public AbilityCommand {
 public:
  Quadruple(Game*);
  void execute();
  ~Quadruple();
};

#endif