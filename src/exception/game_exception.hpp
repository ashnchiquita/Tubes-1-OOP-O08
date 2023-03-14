
#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include "exception.hpp"

class GameException : Exception{
    protected:
        const std::string message = "Invalid game operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

class GameMultiplierException : public GameException{
    private:
        const std::string message = "Invalid point multiplier";
    public:
        const std::string what() const throw() {return message;}
};


#endif