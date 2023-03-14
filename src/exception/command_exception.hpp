
#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include "exception.hpp"

class CommandException : public Exception{
    protected:
        const std::string message = "Invalid command";
    public:
        virtual const std::string what() const throw() {return message;};
};

class CommandNotAvailableException : public CommandException{
    private:
        const std::string message = "You do not have this ability card";
    public:
        const std::string what() const throw() {return message;}
};

class CommandRoundOneException : public CommandException{
    private:
        const std::string message = "Ability cards are unavailable at the first round";
    public:
        const std::string what() const throw() {return message;}
};


#endif