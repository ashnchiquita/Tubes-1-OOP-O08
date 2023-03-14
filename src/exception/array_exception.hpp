
#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include "exception.hpp"

class ArrayException : public Exception{
    protected:
        const std::string message = "Invalid array operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

class ArrayFullException : public ArrayException{
    private:
        const std::string message = "Array is full";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayEmptyException : public ArrayException{
    private:
        const std::string message = "Array is Empty";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayIndexInvalidException : public ArrayException{
    private:
        const std::string message = "Array index is invalid";
    public:
        const std::string what() const throw() {return message;}
};


#endif