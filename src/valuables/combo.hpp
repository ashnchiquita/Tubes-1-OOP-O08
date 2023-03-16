#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <iostream>
#include <vector>
using namespace std;

#include "card.hpp"
#include "valuable.hpp"

enum class ComboType {
  HIGH_CARD,
  PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH
};

const float MAX_CARD_VALUE = 70.0;

class Combo : public Valuable {
 private:
  // ATTRIBUTES

  // Sorted card list forming the combo
  vector<Card> cardList;

  // METHODS

  /**
   * Determine the type of this combo
   *
   * @returns Type of combo
   */
  ComboType determineCombo();

  /**
   * Get the priority of a combo
   *
   * @param type Combo type
   *
   * @returns Priority of the combo
   */
  int getComboPriority(ComboType type);

 public:
  // METHODS

  /**
   * User defined constructor
   *
   * @param cardList List of cards forming the combo
   * @param listSize Size of the list
   */
  Combo(vector<Card> cardList);

  /**
   * Class destructor
   */
  ~Combo();

  /**
   * Calculates the value of the combo
   *
   * @returns Value of the combo
   */
  float value();

  // Combo& operator=(const Combo& other) {
  //   delete[] this->cardList;
  //   this->cardList = other.cardList;
  //   this->comboSize = other.comboSize;
  // }
};

#endif