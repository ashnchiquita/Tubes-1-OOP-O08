#include "ability_command.hpp"

AbilityCommand::AbilityCommand(Game* currentGame) : Command(currentGame) {}

AbilityCommand::~AbilityCommand() {}

void AbilityCommand::turnOffAbility() { this->game->getCurrPlayerRef().getAbilityRef().setAbilityCardStatus(false); }