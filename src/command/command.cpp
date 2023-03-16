#include "command.hpp"

Command::Command(GamePoker* currentGame) {
    this->game = currentGame;
}

Command::~Command() {}