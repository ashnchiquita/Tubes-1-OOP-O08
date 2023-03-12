#ifndef ABILITY_COMMAND_HPP
#define ABILITY_COMMAND_HPP

#include <iostream>
#include "command.hpp"
using namespace std;

class AbilityCommand : public Command {
    public:
        AbilityCommand();
        virtual void execute(Game& currGame) = 0;
};

class Reroll : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

class Quadruple : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

class Quarter : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

class ReverseDirection : public AbilityCommand {
    public:
        void execute(Game& currGame);

};

class SwapCard : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

class SwitchCard : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

class Abilityless : public AbilityCommand {
    public:
        void execute(Game& currGame);
};

#endif
