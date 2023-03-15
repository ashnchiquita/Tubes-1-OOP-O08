#include <algorithm>
#include <iostream>

#include "../valuables/card.hpp"
#include "deck.hpp"
#include "inventory_holder.hpp"
#include "player.hpp"
#include "table_card.hpp"
using namespace std;

// g++ -o main main.cpp ../valuables/card.cpp deck.cpp player.cpp table_card.cpp

int main() {
  // DECK TESTING
  Deck deck;
  deck.print();
  cout << "SHUFFLE\n";
  deck.shuffleDeck();
  deck.print();

  cout << "TOOK CARD 1 BY 1\n";
  int currSize = deck.getSize();
  for (int i = 0; i < currSize; i++) {
    Card temp;
    deck >> &temp;
    temp.displayCard();
  }

  deck.print();

  cout << "=====================\n";

  cout << "INSERT/DELETE DECK\n";
  deck.resetDeck();
  cout << "SIZE: " << deck.getSize() << endl;
  cout << "------ RESET DECK ------\n";
  deck.print();
  Card card1;
  Card card2;
  deck >> &card1;
  deck >> &card2;
  deck.getTop().displayCard();
  card1.displayCard();
  card2.displayCard();
  deck << Card(1, CardColor::BLUE); // try catch dulu, kartu harus unik
  deck.getTop().displayCard();
  cout << "=====================\n";

  // TABLE CARD TESTING
  TableCard table;
  table << Card(5, CardColor::RED);
  table << Card(10, CardColor::BLUE);
  table << Card(11, CardColor::BLUE);
  table << Card(4, CardColor::BLUE);
  table << Card(1, CardColor::BLUE);
  table << Card(2, CardColor::BLUE); // table jg hrs unik

  cout << "INSERT/DELETE TABLE CARD\n";
  for (int i = 0; i < 5; i++) {
    Card temp;
    table >> &temp;
    temp.displayCard();
  }
  cout << "=====================\n";

  // PLAYER TESTING
  Player player1("James", 1000);
  Player player2("Albert", 500);

  cout << "PLAYER COMPARISON\n";
  cout << (player1 > player2) << '\n';
  cout << (player1 < player2) << '\n';
  cout << (player1 == player2) << '\n';
  cout << "=====================\n";

  cout << "INSERT/DELETE PLAYER\n";
  player1 << Card(11, CardColor::BLUE);
  player1 << Card(10, CardColor::BLUE);
  player1 << Card(9, CardColor::BLUE);
  for (int i = 0; i < 2; i++) {
    Card temp;
    player1 >> &temp;
    temp.displayCard();
  }
  cout << "=====================\n";

  cout << "COMBINE PLAYER HAND AND TABLE\n";
  table << Card(5, CardColor::RED);
  table << Card(10, CardColor::BLUE);
  table << Card(11, CardColor::BLUE);
  table << Card(4, CardColor::BLUE);
  table << Card(1, CardColor::BLUE);
  player1 << Card(11, CardColor::RED);
  player1 << Card(10, CardColor::RED);

  Card* testCombine = new Card[7];
  Card* playerHand = new Card[2];
  Card* tableCard = new Card[5];
  
  // Checks for mutation;
  cout << "BEFORE ASSIGNMENT\n";
  playerHand = player1.getAllCards();
  tableCard = table.getAllCards();
  copy(playerHand, playerHand + 2, testCombine);
  copy(tableCard, tableCard + 5, testCombine + 2);
  cout << "AFTER ASSIGNMENT\n";
  playerHand[1] = Card(10, CardColor::GREEN);
  tableCard[1] = Card(10, CardColor::GREEN);
  cout << "TABLE\n";
  for (int i = 0; i < 5; i++) {
    Card temp;
    table >> &temp;
    temp.displayCard();
  }
  cout << "PLAYER\n";
  for (int i = 0; i < 2; i++) {
    Card temp;
    player1 >> &temp;
    temp.displayCard();
  }
  cout << "COMBINED PLAYER AND TABLE\n";
  for (int i = 0; i < 7; i++) {
    testCombine[i].displayCard();
  }
  cout << "=====================\n";


  cout << "PRINT ABILITY\n";
  player1.displayAbility();
  
  delete [] testCombine;
  delete [] playerHand;
  delete [] tableCard;

  return 0;
}