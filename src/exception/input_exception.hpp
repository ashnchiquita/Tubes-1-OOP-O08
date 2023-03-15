
#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include "exception.hpp"

class InputException : public Exception{
    private:
        const std::string message = "Masukan tidak valid. Silakan ulangi lagi.";
    public:
        virtual const std::string what() const throw() {return message;}
};

class InputInvalidCharException : public InputException{
    private:
        const std::string message = "Masukan mengandung karakter tidak valid. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() { return message; }
};

class InputOutOfRangeException : public InputException{
    private:
        const std::string message = "Masukan di luar range yang valid. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

class InputUnavailableException : public InputException{
    private:
        const std::string message = "Masukan tidak available. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};


#endif