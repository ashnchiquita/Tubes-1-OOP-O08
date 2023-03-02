#ifndef COMBO_HPP
#define COMBO_HPP

#include <vector>

#include "card.hpp"
#include "valuable.hpp"
using namespace std;

class Combo : public Valuable {
 private:
  // List of cards forming the combo
  Card* cardList;

 public:
  /**
   * User defined constructor
   *
   * @param cardList : Array of cards
   */
  Combo(Card* cardList);

  /**
   * Destructor
   */
  ~Combo();

  /**
   * Get the value of this combo
   *
   * @returns Value for this combo
   */
  float value();
};

#endif