#ifndef HELP_HPP
#define HELP_HPP

#include "basic_command.hpp"

class Help : public BasicCommand {
    public:
        Help(GamePoker*);
        void execute();
        ~Help();
};

#endif