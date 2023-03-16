#include "runner.hpp"
#include "../game/game_poker.hpp"
#include "../game/game_cangkul.hpp"
#include "../input_handler/input_handler.hpp"
#include "../exception/exception.hpp"

#include <iostream>

/* TODO: handle Y/N input untuk retry */
Runner::Runner() : running(true) {}
Runner::~Runner(){}

void Runner::gameChoice(){
    bool valid = 0;
    do{
        try{
            std::cout << "Permainan yang tersedia" << endl;
            std::cout << "1. Poker" << endl;
            std::cout << "2. Cangkul" << endl;
            this->choiceHandler.setInput("Masukkan pilihan: ", 1, 2);
            
            this->choice = this->choiceHandler.getInput();
            valid = 1;
        }catch(Exception& e){
            std::cout << e.what() << std::endl;
        }
    } while (!valid);
}

void Runner::continueChoice(){
    bool valid = 0;
    do{
        try{
            std::cout << "Permainan selesai" << endl;
            std::cout << "1. Main lagi" << endl;
            std::cout << "2. Exit" << endl;
            this->choiceHandler.setInput("Masukkan pilihan: ", 1, 2);

            this->choice = this->choiceHandler.getInput();
            if(this->choice == 2) this->running = false;
            valid = 1;

        }catch(Exception& e){
            std::cout << e.what() << std::endl;
        }
        
    } while (!valid);
}

void Runner::startGame(){
    if(this->choice == 1){
        GamePoker g;
        do {
            g.runGame();
            if (!g.isFinished()) {
                g.resetGame();
            }
        } while (!g.isFinished());
    }
    else if (this->choice == 2){
        GameCangkul g;
        do {
            g.runGame();
        } while (!g.isFinished());
    }
}

void Runner::run() {
    do{
        gameChoice();
        startGame();
        continueChoice();

    } while(this->running);
}