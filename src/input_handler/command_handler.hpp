#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "input_handler.hpp"
#include "../exception/command_exception.hpp"

using namespace std;

template <typename T>
class CommandHandler : public InputHandler<T>{
    private:
        static string commandStrings[10];
        static string ynStrings[4];
    public:
        CommandHandler();
        ~CommandHandler();
        void yesNoCommand(string);
        void turnCommand(string, bool, string);
};
template <typename T>
CommandHandler<T>::CommandHandler() {}

template <typename T>
CommandHandler<T>::~CommandHandler() {}

template <typename T>
string CommandHandler<T>::ynStrings[4] = {"Y", "y", "N", "n"};

template <typename T>
string CommandHandler<T>::commandStrings[10] = {
                        "DOUBLE",
                        "HALF",
                        "NEXT",
                        "REROLL",
                        "QUARTER",
                        "QUADRUPLE",
                        "REVERSE",
                        "SWAP",
                        "SWITCH",
                        "ABILITYLESS"
                        };

template <typename T>
void CommandHandler<T>::yesNoCommand(string prompt){
    try{
        this->setInput(prompt, ynStrings, 4);
    }
    catch(Exception& e){
        throw CommandException();
    }
}

template <typename T>
void CommandHandler<T>::turnCommand(string prompt, bool validity, string abilitytype){
    this->setInput(prompt, commandStrings, 10);

    if (validity){
        if(this->input == abilitytype || this->input == string("DOUBLE") || this->input == string("HALF") || this->input == string("NEXT"))
            return;
        else
            throw CommandNotAvailableException();
    }
    else{
        if (!(this->input == string("DOUBLE") || this->input == string("HALF") || this->input == string("NEXT"))) {
            throw CommandRoundOneException();
        }
    }
}

#endif