#ifndef NEXT_HPP
#define NEXT_HPP

#include "basic_command.hpp"

class Next : public BasicCommand {
    public:
        Next(Game*);
        void execute();
        ~Next();
};

#endif