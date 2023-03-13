#include <iostream>
using namespace std;


#include "../valuables/card.cpp"
#include "deck.cpp"
#include "inventory_holder.cpp"
#include "player.cpp"
#include "table_card.cpp"

int main(){
    Deck deck;
    cout << "PRINT DECK\n";
    deck.shuffleDeck();
    for (int i = 0; i < 52; i++) {
        Card temp;
        deck >> &temp;
        temp.displayCard();
    }

    cout << "\n======================\n";
    deck.shuffleDeck();
    for (int i = 0; i < 52; i++) {
        Card temp;
        deck >> &temp;
        temp.displayCard();
    }

    return 0;
}