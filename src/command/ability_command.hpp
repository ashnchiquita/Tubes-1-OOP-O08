#ifndef ABILITY_COMMAND_HPP
#define ABILITY_COMMAND_HPP

#include <iostream>

#include "command.hpp"
using namespace std;

class AbilityCommand : public Command {
 public:
  AbilityCommand(Game*);
  virtual void execute() = 0;
  void turnOffAbility();
};

class Reroll : public AbilityCommand {
 public:
  Reroll(Game*);
  void execute();
};

class Quadruple : public AbilityCommand {
 public:
  Quadruple(Game*);
  void execute();
};

class Quarter : public AbilityCommand {
 public:
  Quarter(Game*);
  void execute();
};

class ReverseDirection : public AbilityCommand {
 public:
  ReverseDirection(Game*);
  void execute();
};

class SwapCard : public AbilityCommand {
 public:
  SwapCard(Game*);
  void execute();
};

class SwitchCard : public AbilityCommand {
 public:
  SwitchCard(Game*);
  void execute();
};

class Abilityless : public AbilityCommand {
 public:
  Abilityless(Game*);
  void execute();
};

#endif