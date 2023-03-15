#ifndef HALF_HPP
#define HALF_HPP

#include "basic_command.hpp"

class Half : public BasicCommand {
    public:
        Half(Game*);
        void execute();
        ~Half();
};

#endif