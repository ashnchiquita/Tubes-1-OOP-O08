#include "card.hpp"

#include <iostream>
#include <map>
using namespace std;

/**
 * Class default constructor
 */
Card::Card() {
  this->num = 0;
  this->color = CardColor::GREEN;
}

/**
 * User defined constructor
 *
 * @param num Card number
 * @param color Card color
 */
Card::Card(int num, CardColor color) {
  this->num = num;
  this->color = color;
}

/**
 * Copy constructor
 *
 * @param other Copied card
 */
Card::Card(const Card& other) {
  this->num = other.num;
  this->color = other.color;
}

/**
 * Assignment operator
 *
 * @param other Assigned card
 */
Card Card::operator=(const Card& other) {
  this->num = other.num;
  this->color = other.color;

  return *this;
}

/**
 * Calculates the value of the card
 *
 * @returns Value of the card
 */
float Card::value() { return float(this->num) + float(int(this->color)) * 0.2; }

/**
 * Card number getter
 *
 * @returns Card number
 */
int Card::getNum() const { return this->num; }

/**
 * Card number setter
 *
 * @param num Card number
 */
void Card::setNum(int num) { this->num = num; }

/**
 * Card color getter
 *
 * @returns Card color
 */
CardColor Card::getColor() const { return this->color; }

/**
 * Card color setter
 *
 * @param color Card color
 */
void Card::setColor(CardColor color) { this->color = color; }

/**
 * Check for the validity of the card
 *
 * @returns True if the card is valid
 */
bool Card::isValidCard() const { return this->num >= 1 && this->num <= 13; }

/**
 * Displays card to the screen
 */
void Card::displayCard() {
  map<CardColor, string> colorMap;
  colorMap[CardColor::GREEN] = "hijau";
  colorMap[CardColor::BLUE] = "biru";
  colorMap[CardColor::YELLOW] = "kuning";
  colorMap[CardColor::RED] = "merah";

  cout << "Kartu " << this->num << " warna " << colorMap[this->color] << '\n';
}