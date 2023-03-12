#include "combo.hpp"

#include <algorithm>
#include <map>
using namespace std;

/**
 * User defined constructor
 *
 * @param cardList List of cards forming the combo
 * @param listSize Size of the list
 */
Combo::Combo(const Card* cardList, int listSize) {
  this->cardList = new Card[listSize];
  this->comboSize = listSize;

  int* countArr = new int[14];
  int** colorArr = new int*[14];
  for (int i = 0; i < 14; i++) {
    colorArr[i] = new int[4];
  }

  for (int i = 0; i < listSize; i++) {
    countArr[cardList[i].getNum()]++;
    colorArr[cardList[i].getNum()][int(cardList[i].getColor())]++;
  }

  int index = 0, count = 1;
  while (index != 5) {
    for (int i = 0; i < 14; i++) {
      if (countArr[i] == count) {
        for (int j = 0; j < 4; j++) {
          if (colorArr[i][j] > 0) {
            (this->cardList[index]) = {i, static_cast<CardColor>(j)};
            index++;
          }
        }
      }
    }
    count++;
  }

  delete[] countArr;
  delete[] colorArr;
}

/**
 * Class destructor
 */
Combo::~Combo() { delete[] cardList; }

/**
 * Determine the type of this combo
 *
 * @returns Type of combo
 */
ComboType Combo::determineCombo() {
  Card* cards = this->cardList;

  map<int, int> cardCount;
  for (int i = 0; i < this->comboSize; i++) {
    cardCount[cards[i].getNum()]++;
  }

  int countPair = 0, iterationCount = 0;
  for (auto it = cardCount.begin(); it != cardCount.end(); it++) {
    countPair = it->second > 1 ? countPair + 1 : countPair;
    iterationCount++;
  }

  if (iterationCount == 2) {
    return countPair == 2 ? ComboType::FULL_HOUSE : ComboType::FOUR_OF_A_KIND;
  } else if (iterationCount == 3) {
    return countPair == 2 ? ComboType::TWO_PAIR : ComboType::THREE_OF_A_KIND;
  } else if (iterationCount == 4) {
    return ComboType::PAIR;
  }

  bool isSameColor = true;
  for (int i = 0; i < this->comboSize - 1; i++) {
    if (cards[i].getColor() != cards[i + 1].getColor()) {
      isSameColor = false;
      break;
    }
  }

  if (cards[this->comboSize - 1].getNum() - cards[0].getNum() + 1 ==
      this->comboSize) {
    return isSameColor ? ComboType::STRAIGHT_FLUSH : ComboType::STRAIGHT;
  } else if (isSameColor) {
    return ComboType::FLUSH;
  }

  return ComboType::HIGH_CARD;
}

/**
 * Get the priority of a combo
 *
 * @param type Combo type
 *
 * @returns Priority of the combo
 */
int Combo::getComboPriority(ComboType type) {
  switch (type) {
    case ComboType::HIGH_CARD:
      return 1;
    case ComboType::PAIR:
      return 2;
    case ComboType::TWO_PAIR:
      return 3;
    case ComboType::THREE_OF_A_KIND:
      return 4;
    case ComboType::STRAIGHT:
      return 5;
    case ComboType::FLUSH:
      return 6;
    case ComboType::FULL_HOUSE:
      return 7;
    case ComboType::FOUR_OF_A_KIND:
      return 8;
    case ComboType::STRAIGHT_FLUSH:
      return 9;
    default:
      return 0;
  }
}

/**
 * Calculates the value of the combo
 *
 * @returns Value of the combo
 */
float Combo::value() {
  ComboType comboType = this->determineCombo();
  int comboPriority = this->getComboPriority(comboType);

  float cardValue = 0.0;
  for (int i = 0; i < this->comboSize; i++) {
    cardValue += this->cardList[i].value();
  }

  return (cardValue / MAX_CARD_VALUE) +
         this->cardList[this->comboSize - 1].value() * 10 + comboPriority * 100;
}