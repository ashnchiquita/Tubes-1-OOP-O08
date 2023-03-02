#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include <iostream>
#include <vector>
#include "card.hpp"
#include "valuable.hpp"

using namespace std;

class Combo : public Valuable {
    protected:
        vector<Card> card;
    public: 
        float Value();

        float pair();
        float twoPair();
        float threeOfAKind();
        float straight();
        float flush();
        float fullHouse();
        float fourOfAKind();
        float straightFlush();
};

#endif