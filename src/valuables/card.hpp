#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "valuable.hpp"

enum class CardColor { GREEN, BLUE, YELLOW, RED };

class Card : public Valuable {
 private:
  // ATTRIBUTES

  // Card number [1-13]
  int num;
  // Card color
  CardColor color;

 public:
  // METHOD

  /**
   * Class default constructor
   */
  Card();

  /**
   * User defined constructor
   *
   * @param num Card number
   * @param color Card color
   */
  Card(int num, CardColor color);

  /**
   * Copy constructor
   *
   * @param other Copied card
   */
  Card(const Card& other);

  /**
   * Assignment operator
   *
   * @param other Assigned card
   */
  Card operator=(const Card& other);

  /**
   * Checks for equality of two cards
   *
   * @param other Other card
   *
   * @returns True if the cards are equal
   */
  bool operator==(const Card& other);

  /**
   * Calculates the value of the card
   *
   * @returns Value of the card
   */
  float value();

  /**
   * Card number getter
   *
   * @returns Card number
   */
  int getNum() const;

  /**
   * Card number setter
   *
   * @param num Card number
   */
  void setNum(int num);

  /**
   * Card color getter
   *
   * @returns Card color
   */
  CardColor getColor() const;

  /**
   * Card color setter
   *
   * @param color Card color
   */
  void setColor(CardColor color);

  /**
   * Check for the validity of the card
   *
   * @returns True if the card is valid
   */
  bool isValidCard() const;

  /**
   * Displays card to the screen
   */
  void displayCard();

  bool operator<(const Card& other) { return this->getNum() < other.getNum(); }
};

#endif