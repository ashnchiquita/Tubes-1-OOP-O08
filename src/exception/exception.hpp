
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception{
    protected:
        const std::string message;
    public:
        virtual const std::string what() const throw() = 0;
};

#endif


