#ifndef NEXT_HPP
#define NEXT_HPP

#include "basic_command.hpp"

class Next : public BasicCommand {
    public:
        Next(GamePoker* g);
        void execute();
        ~Next();
};

#endif