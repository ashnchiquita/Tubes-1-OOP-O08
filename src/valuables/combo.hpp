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

        float Pair();
        float TwoPair();
        float ThreeOfAKind();
        float Straight();
        float Flush();
        float FullHouse();
        float FourOfAKind();
        float StraightFlush();
};

#endif