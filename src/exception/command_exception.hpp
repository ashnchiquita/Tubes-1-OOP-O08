
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
        const std::string messageSnippet1 = "Ets, tidak bisa. Kamu tidak punya kartu Ability ";
        const std::string messageSnippet2 = ". Silahkan lakukan perintah lain.";
        std::string cardString;
    public:
        CommandNotAvailableException(std::string card) : cardString(card){};
        const std::string what() const throw() {return (messageSnippet1 + cardString + messageSnippet2);}
};

class CommandRoundOneException : public CommandException{
    private:
        const std::string message = "Kartu ability tidak dapat dipakai pada ronde pertama";
    public:
        const std::string what() const throw() {return message;}
};

class CommandDisabledException : public CommandException{
    private:
        const std::string messageSnippet1 = "Oops, kartu ability ";
        const std::string messageSnippet2 = "mu telah dimatikan sebelumnya :(\nSilahkan lakukan perintah lain.";
        std::string cardString;
    public:
        CommandDisabledException(std::string card) : cardString(card){};
        const std::string what() const throw() {return (messageSnippet1 + cardString + messageSnippet2);}
};


#endif