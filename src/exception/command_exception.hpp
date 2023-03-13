
#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include "exception.hpp"

class CommandException : Exception{
    protected:
        const std::string message = "Invalid command";
    public:
        virtual const std::string what() const throw() {return message;};
};

class CommandNotAvailable : public CommandException{
    private:
        const std::string message = "Ability not available";
    public:
        const std::string what() const throw() {return message;}
};

class CommandInvalid : public CommandException{
    private:
        const std::string message = "Ability is invalid";
    public:
        const std::string what() const throw() {return message;}
};


#endif