
#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include "exception.hpp"

class FileException : Exception{
    protected:
        const std::string message = "Invalid file operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

class GameMultiplierException : public FileException{
    private:
        const std::string message = "Invalid point multiplier";
    public:
        const std::string what() const throw() {return message;}
};

// Kalo first charnya bukan M H B K
// kalo number nya < 1 ato > 13
// kalo kurang dari 52 line (card)
// kalo lebih dari 52 line (card)
// kalo ada card yang sama
// kalo ada card yg ga valid



#endif