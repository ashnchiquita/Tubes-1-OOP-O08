#include "basic_command.hpp"
#include "../command.hpp"

BasicCommand::BasicCommand(GamePoker* currentGame) : Command(currentGame) {}

BasicCommand::~BasicCommand() {}