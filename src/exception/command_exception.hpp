
#ifndef COMMAND_EXCEPTION_H
#define COMMAND_EXCEPTION_H

#include "exception.hpp"

class CommandException : public Exception{
    protected:
        const std::string message = "Masukan tidak valid. Silakan ulangi lagi.";
    public:
        virtual const std::string what() const throw() {return message;};
};

class CommandNotAvailableException : public CommandException{
    private:
        const std::string messageSnippet1 = "Eits, tidak bisa. Kamu tidak punya kartu Ability ";
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
        const std::string messageSnippet2 = "-mu telah dimatikan sebelumnya :(\nSilakan lakukan perintah lain.";
        std::string cardString;
    public:
        CommandDisabledException(std::string card) : cardString(card){};
        const std::string what() const throw() {return (messageSnippet1 + cardString + messageSnippet2);}
};

class CommandCardUsedException : public CommandException{
    private:
        const std::string messageSnippet1 = "Oops, kartu ability ";
        const std::string messageSnippet2 = "-mu telah digunakan, giliranmu terbuang sia-sia.";
        std::string cardString;
    public:
        CommandCardUsedException(std::string card) : cardString(card){};
        const std::string what() const throw() {return (messageSnippet1 + cardString + messageSnippet2);}
};

class CommandHelpException : public CommandException{
    private:
        const std::string message = "Silahkan pilih command yang lain.";
    public:
        CommandHelpException(){};
        const std::string what() const throw() {return message;}
};

#endif