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
  virtual ~AbilityCommand();
};

class Reroll : public AbilityCommand {
 public:
  Reroll(Game*);
  void execute();
  ~Reroll();
};

class Quadruple : public AbilityCommand {
 public:
  Quadruple(Game*);
  void execute();
  ~Quadruple();
};

class Quarter : public AbilityCommand {
 public:
  Quarter(Game*);
  void execute();
  ~Quarter();
};

class ReverseDirection : public AbilityCommand {
 public:
  ReverseDirection(Game*);
  void execute();
  ~ReverseDirection();
};

class SwapCard : public AbilityCommand {
 public:
  SwapCard(Game*);
  void execute();
  ~SwapCard();
};

class SwitchCard : public AbilityCommand {
 public:
  SwitchCard(Game*);
  void execute();
  ~SwitchCard();
};

class Abilityless : public AbilityCommand {
 public:
  Abilityless(Game*);
  void execute();
  ~Abilityless();
};

#endif