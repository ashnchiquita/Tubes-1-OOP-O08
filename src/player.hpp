#ifndef player_hpp
#define player_hpp

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Player {
    public:
        string name;
        int selfPoint;
        int card;

        Player();
        Player(string nama, int cardNum);
        void addPoint(int add);
        void setCard(int x);
        int getCard();
        void print();
};

#endif