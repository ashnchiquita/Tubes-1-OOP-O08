#include "../combo.cpp"
#include "../card.cpp"
#include "../valuable.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {
  // Shuffle deck
  srand(time(nullptr));
  vector<int> deck;
  for (int i = 1; i <= 52; i++) {
    deck.push_back(i);
  }

  // Create random combo
  Card** cardList = new Card*[10];
  int j = 0;
  for (int i = 0; i < 10; i++) {
    cardList[i] = new Card[5];
    for (int k = 0; k < 5; k++) {
      int num = (deck[j] - 1) % 13 + 1;
      CardColor color = static_cast<CardColor>((deck[j] - 1) / 13);
      cardList[i][k] = *(new Card(num, color));
      j++;
    }
  }

  // Calculate combo value
  float comboValues[10];
  int comboPrio[10];

  // Print combos in descending order
  bool checked[10];
  for (int i = 0; i < 10; i++) {
    checked[i] = false;
  }
  for (int i = 0; i < 10; i++) {
    float maxVal;
    int maxIndex;

    int j = 0;
    while (checked[j] != false) {
      j++;
    }
    maxVal = comboValues[j];
    maxIndex = j;

    for (int k = 0; k < 10; k++) {
      if (!checked[k]) {
        if (comboValues[k] > maxVal) {
          maxVal = comboValues[k];
          maxIndex = k;
        }
      }
    }

    checked[maxIndex] = true;

    cout << "Combo " << i << " : ";
    for (int k = 0; k < 5; k++) {
      printf("%2d", cardList[maxIndex][k].getNum());
      cout << '(' << int(cardList[maxIndex][k].getColor()) << ") ";
    }
    cout << "| Value : " << comboValues[maxIndex] << '\n';
  }

  return 0;
}