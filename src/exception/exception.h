
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception{
    protected:
        int errorCode;
        std::string errorMsg;
    public:
        virtual std::string getMsg() = 0;
};

class ArrayException : public Exception{
    private:
        std::string errorMsg[3] = {
            "Index out of bounds",
            "Array overflowed",
            "Array empty"
        };
    public:
        ArrayException(int);
        std::string msg(){return errorMsg[errorCode];};
};

class CommandException : public Exception{
    private:
        std::string errorMsg[2] = {
            "Invalid ability",
            "Ability not available"
        };
    public:
        CommandException(int);
        std::string msg(){return errorMsg[errorCode];};
};

class InputException : public Exception{
    private:
        std::string errorMsg = "Invalid input";
    public:
        std::string msg(){return errorMsg;};
};

#endif