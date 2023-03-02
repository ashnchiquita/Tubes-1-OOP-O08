#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "valuable.hpp"

class Card {
    protected:
        int num;                    // 1-13
        string color;               // G, B, Y, R
    public:
        Card();                   
        Card(int, string);          
        Card(const Card&);          
        virtual ~Card();           

        int getNum() const;
        void setNum(int);
        string getColor() const;
        void setColor(string);

        bool isValidCard() const;
        float getValue() const;
        void displayCard();
};

#endif