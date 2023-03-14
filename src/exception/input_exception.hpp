
#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include "exception.hpp"

class InputException : public Exception{
    private:
        const std::string message = "Invalid input";
    public:
        virtual const std::string what() const throw() {return message;}
};

class InputInvalidCharException : public InputException{
    private:
        const std::string message = "Unexpected char in input";
    public:
        const std::string what() const throw() {return message;}
};

class InputOutOfRangeException : public InputException{
    private:
        const std::string message = "Input is out of range";
    public:
        const std::string what() const throw() {return message;}
};

class InputUnavailableException : public InputException{
    private:
        const std::string message = "Input is not available";
    public:
        const std::string what() const throw() {return message;}
};


#endif