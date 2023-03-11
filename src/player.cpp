#include "player.hpp"

Player::Player() : name("halo"), selfPoint(0), card(0) {}
Player::Player(string nama, int cardNum) : name(nama), selfPoint(0), card(cardNum) {
    cout << "Created player named " << this->name << " and " << this->card << " card." << endl;
}
void Player::addPoint(int add) {
    this->selfPoint += add;
}
void Player::setCard(int x) {
    this->card = x;
}
int Player::getCard() {
    return this->card;
}
void Player::print() {
    cout << "Nama : " << this->name << endl;
    cout << "Self Point : " << this->selfPoint << endl;
    cout << "Kartu : " << this->card << endl;
}