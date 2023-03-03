#ifndef _ACTION_HPP_
#define _ACTION_HPP_

#include <iostream>
#include <string>

using namespace std;

class Action{
    protected:

    public:
    Action();
    ~Action();
    virtual void execute() = 0;
};

#endif