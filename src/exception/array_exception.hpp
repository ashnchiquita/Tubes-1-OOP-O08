
#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include "exception.hpp"

class ArrayException : Exception{
    protected:
        const std::string message = "Invalid array operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

class ArrayFull : public ArrayException{
    private:
        const std::string message = "Array is full";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayEmpty : public ArrayException{
    private:
        const std::string message = "Array is Empty";
    public:
        const std::string what() const throw() {return message;}
};

class ArrayIndexInvalid : public ArrayException{
    private:
        const std::string message = "Array index is invalid";
    public:
        const std::string what() const throw() {return message;}
};


#endif