#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
using namespace std;

class Action{
    protected:

    public:
};

class AbilityCmd : public Action{
    protected:
        
    public:
        AbilityCmd();
        ~AbilityCmd();
};

class Reroll : public AbilityCmd{

};

class Quadruple : public AbilityCmd{

};

class Quarter : public AbilityCmd{

};

class ReverseDirection : public AbilityCmd{

};

class SwapCard : public AbilityCmd{

};

class SwitchCard : public AbilityCmd{

};

class AbilityLess : public AbilityCmd{

};

#endif
