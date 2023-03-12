
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception{
    protected:
        const std::string message;
    public:
        virtual const std::string what() const throw() = 0;
};

class ArrayFull : public Exception{
    private:
        const std::string message = "Array is full";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayEmpty : public Exception{
    private:
        const std::string message = "Array is Empty";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayIndexInvalid : public Exception{
    private:
        const std::string message = "Array index is invalid";
    public:
        const std::string what() const throw() {return message;}
};

class CommandNotAvailable : public Exception{
    private:
        const std::string message = "Ability not available";
    public:
        const std::string what() const throw() {return message;}
};

class CommandInvalid : public Exception{
    private:
        const std::string message = "Ability is invalid";
    public:
        const std::string what() const throw() {return message;}
};

class InputException : public Exception{
    private:
        const std::string message = "Invalid input";
    public:
        const std::string what() const throw() {return message;};
};

#endif