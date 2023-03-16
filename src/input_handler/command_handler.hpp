#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "input_handler.hpp"
#include "../exception/command_exception.hpp"
#include <iostream>

using namespace std;

template <typename T>
class CommandHandler : public InputHandler<T>{
    private:
        static string commandStrings[11];
        static string ynStrings[4];
    public:
        CommandHandler();
        ~CommandHandler();
        void yesNoCommand(string);
        void turnCommand(string, bool*, string);
};

template <typename T>
CommandHandler<T>::CommandHandler() {}

template <typename T>
CommandHandler<T>::~CommandHandler() {}

template <typename T>
string CommandHandler<T>::ynStrings[4] = {"Y", "y", "N", "n"};

template <typename T>
string CommandHandler<T>::commandStrings[11] = {
                        "DOUBLE",
                        "HALF",
                        "NEXT",
                        "REROLL",
                        "QUARTER",
                        "QUADRUPLE",
                        "REVERSE",
                        "SWAPCARD",
                        "SWITCH",
                        "ABILITYLESS",
                        "HELP"
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
void CommandHandler<T>::turnCommand(string prompt, bool constraints[3], string abilitytype){
    this->setInput(prompt, commandStrings, 11);

    if (constraints[0]){
        if (this->input == abilitytype)
            if (!constraints[1]) throw CommandDisabledException(abilitytype);
            else if (constraints[2]) throw CommandCardUsedException(abilitytype);
            else return;
        else if(this->input == string("DOUBLE") || this->input == string("HALF") || this->input == string("NEXT") || this->input == string("HELP"))
            return;
        else
            throw CommandNotAvailableException(this->input);
    }
    else{
        if (!(this->input == string("DOUBLE") || this->input == string("HALF") || this->input == string("NEXT") || this->input == string("HELP"))) {
            throw CommandRoundOneException();
        }
    }
}

#endif