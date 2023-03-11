#include <iostream>

#include "combo.hpp"
using namespace std;

int main() {
  Card card1(5, CardColor::GREEN);
  Card card2(4, CardColor::BLUE);
  Card card3(3, CardColor::YELLOW);
  Card card4(6, CardColor::RED);
  Card card5(7, CardColor::BLUE);
  Card cardArr[] = {card1, card2, card3, card4, card5};
  Combo combo = {cardArr, 5};
  cout << combo.value() << '\n';
  return 0;
}