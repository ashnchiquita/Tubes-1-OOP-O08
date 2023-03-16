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
Combo::Combo(vector<Card> cards) {
  this->cardList = cards;

  vector<int> countArr; // 14
  for (int i = 0; i < 14; i++) {
    countArr.push_back(0);
  }

  vector< vector<int> > colorArr; // 14 x 4
  for (int i = 0; i < 14; i++) {
    vector <int> tempVec;
    for (int j = 0; j < 4; j++) {
      tempVec.push_back(0);
    }
    colorArr.push_back(tempVec);
  }

  for (int i = 0; i < cards.size(); i++) {
    countArr[cards[i].getNum()]++;
    colorArr[cards[i].getNum()][int(cardList[i].getColor())]++;
  }

  int index = 0, count = 1;
  while (index != 5) {
    for (int i = 1; i < 14; i++) {
      if (countArr[i] == count) {
        for (int j = 0; j < 4; j++) {
          if (colorArr[i][j] > 0) {
            (this->cardList[index]) = Card(i, static_cast<CardColor>(j));
            index++;
          }
        }
      }
    }
    count++;
  }

}

/**
 * Class destructor
 */
Combo::~Combo() {}

/**
 * Determine the type of this combo
 *
 * @returns Type of combo
 */
ComboType Combo::determineCombo() {
  vector<Card> cards = this->cardList;

  map<int, int> cardCount;
  for (int i = 0; i < this->cardList.size(); i++) {
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
  for (int i = 0; i < this->cardList.size() - 1; i++) {
    if (cards[i].getColor() != cards[i + 1].getColor()) {
      isSameColor = false;
      break;
    }
  }

  if (cards[this->cardList.size() - 1].getNum() - cards[0].getNum() + 1 ==
      this->cardList.size()) {
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
  if (type == ComboType::HIGH_CARD) {
    return 1; 
  } else if (type == ComboType::PAIR) {
    return 2; 
  } else if (type == ComboType::TWO_PAIR) {
    return 3; 
  } else if (type == ComboType::THREE_OF_A_KIND) {
    return 4; 
  } else if (type == ComboType::STRAIGHT) {
    return 5; 
  } else if (type == ComboType::FLUSH) {
    return 6; 
  } else if (type == ComboType::FULL_HOUSE) {
    return 7; 
  } else if (type == ComboType::FOUR_OF_A_KIND) {
    return 8; 
  } else if (type == ComboType::STRAIGHT_FLUSH) {
    return 9; 
  } else {
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
  for (int i = 0; i < this->cardList.size(); i++) {
    cardValue += this->cardList[i].value();
  }

  return (cardValue / MAX_CARD_VALUE) +
         this->cardList[this->cardList.size() - 1].value() * 10 +
         comboPriority * 1000;
}