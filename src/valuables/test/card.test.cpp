#include "../card.hpp"

#include <iostream>

#include "../valuable.hpp"
using namespace std;

int main() {
  // Default constructor
  Card card1;

  // User defined constructor
  Card card2(13, CardColor::RED);

  // Copy constructor
  Card card3 = card2;

  // Equality operator
  cout << (card3 == card2 ? "Equal\n" : "Not equal\n");

  // Card value
  cout << card3.value() << '\n';
  cout << card1.value() << '\n';

  // Getter-setter
  card3.displayCard();
  cout << "Num: " << card3.getNum() << '\n';
  cout << "Color: " << int(card3.getColor()) << '\n';
  card3.setNum(5);
  card3.setColor(CardColor::GREEN);
  cout << "Num: " << card3.getNum() << '\n';
  cout << "Color: " << int(card3.getColor()) << '\n';

  // Card validity
  cout << (card3.isValidCard() ? "Valid\n" : "Not valid\n");
  cout << (card1.isValidCard() ? "Valid\n" : "Not valid\n");

  return 0;
}