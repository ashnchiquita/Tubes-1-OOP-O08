
#ifndef CONFIG_EXCEPTION_H
#define CONFIG_EXCEPTION_H

#include "exception.hpp"

class ConfigException : public Exception{
    protected:
        const std::string message = "Operasi konfigurasi deck invalid. Silakan ulangi lagi.";
    public:
        virtual const std::string what() const throw() {return message;};
};

//ini buat input nomor yang gak valid (angka diisi huruf, kalo redundan hapus aja, pake yang invalid number)
class ConfigFileException : public ConfigException{
    private:
        const std::string message = "File konfigurasi deck tidak ditemukan. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input nomor yang gak valid (angka diisi huruf, kalo redundan hapus aja, pake yang invalid number)
class ConfigInvalidCharException : public ConfigException{
    private:
        const std::string message = "File konfigurasi deck mengandung karakter ilegal. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input warna yang gak valid
class ConfigInvalidColorException : public ConfigException{
    private:
        const std::string message = "Warna kartu pada file konfigurasi deck tidak valid. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

//ini buat input number yang gak valid (< 1 ato > 13)
class ConfigInvalidNumberException : public ConfigException{
    private:
        const std::string message = "Angka kartu pada file konfigurasi deck tidak valid. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

//kalo kartu > 52
class ConfigTooManyException : public ConfigException{
    private:
        const std::string message = "Kartu pada file config terlalu banyak. Silakan ulangi lagi." ;
    public:
        const std::string what() const throw() {return message;}
};

//kalo kartu < 52
class ConfigNotEnoughException : public ConfigException{
    private:
        const std::string message = "Kartu pada file config terlalu sedikit. Silakan ulangi lagi.";
    public:
        const std::string what() const throw() {return message;}
};

//kalo ada kartu yang sama
class ConfigSameCardException : public ConfigException{
    private:
        const std::string message = "Kartu duplikat terdapat pada config. Silakan ulangi lagi.";
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