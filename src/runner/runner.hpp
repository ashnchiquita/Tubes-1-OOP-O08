#ifndef RUNNER_H
#define RUNNER_H

#include "../input_handler/input_handler.hpp"
#include "../game/game_poker.hpp"
#include "../game/game_cangkul.hpp"
#include "../input_handler/input_handler.hpp"
#include "../exception/exception.hpp"

class Runner{
    private:
        InputHandler<int> choiceHandler;
        int choice;
        bool running;
    public:
        Runner();
        ~Runner();
        void gameChoice();
        void continueChoice();
        void startGame();
        void run();
};

#endif