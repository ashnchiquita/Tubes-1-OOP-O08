#ifndef ABILITY_COMMAND_HPP
#define ABILITY_COMMAND_HPP

#include "../command.hpp"

class AbilityCommand : public Command {
  public:
    AbilityCommand(Game*);
    virtual void execute() = 0;
    void turnOffAbility();
    virtual ~AbilityCommand();
};

#endif