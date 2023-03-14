
#ifndef CONFIG_EXCEPTION_H
#define CONFIG_EXCEPTION_H

#include "exception.hpp"

class ConfigException : Exception{
    protected:
        const std::string message = "Invalid Config operation";
    public:
        virtual const std::string what() const throw() {return message;};
};

//ini buat input nomor yang gak valid (angka diisi huruf, kalo redundan hapus aja, pake yang invalid number)
class ConfigFileException : public ConfigException{
    private:
        const std::string message = "Error opening file";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input nomor yang gak valid (angka diisi huruf, kalo redundan hapus aja, pake yang invalid number)
class ConfigInvalidCharException : public ConfigException{
    private:
        const std::string message = "Unexpected char in config";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input warna yang gak valid
class ConfigInvalidColorException : public ConfigException{
    private:
        const std::string message = "Card color in config is invalid";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input number yang gak valid (< 1 ato > 13)
class ConfigInvalidNumberException : public ConfigException{
    private:
        const std::string message = "Card number in config is out of range";
    public:
        const std::string what() const throw() {return message;}
};

//kalo kartu > 52
class ConfigTooManyException : public ConfigException{
    private:
        const std::string message = "Too many cards in config";
    public:
        const std::string what() const throw() {return message;}
};

//kalo kartu < 52
class ConfigNotEnoughException : public ConfigException{
    private:
        const std::string message = "Not enough cards in config";
    public:
        const std::string what() const throw() {return message;}
};

//kalo ada kartu yang sama
class ConfigSameCardException : public ConfigException{
    private:
        const std::string message = "Duplicate cards in config";
    public:
        const std::string what() const throw() {return message;}
};

//kalo ada kartu yang invalid? kalo apa invalidnya? kalo bisa pake exception yang diatas ganti aja, keliatannya redundan
class ConfigInvalidCardException : public ConfigException{
    private:
        const std::string message = "Invalid card in config";
    public:
        const std::string what() const throw() {return message;}
};

// Kalo first charnya bukan M H B K
// kalo number nya < 1 ato > 13
// kalo kurang dari 52 line (card)
// kalo lebih dari 52 line (card)
// kalo ada card yang sama
// kalo ada card yg ga valid

#endif