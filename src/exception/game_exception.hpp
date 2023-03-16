
#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include "exception.hpp"

class GameException : public Exception{
    protected:
        const std::string message = "Invalid game operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

class GameMultiplierException : public GameException{
    private:
        const std::string message = "Sayangnya poin hadiah masih kurang untuk melakukan command ini. Poin hadiah tidak berubah.. Giliran dilanjut!";
    public:
        const std::string what() const throw() {return message;}
};


#endif