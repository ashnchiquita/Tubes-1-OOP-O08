#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "basic_command.hpp"

class Double : public BasicCommand {
    public:
        Double(GamePoker*);
        void execute();
        ~Double();
};

#endif