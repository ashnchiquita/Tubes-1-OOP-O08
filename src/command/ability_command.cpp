#include "ability_command.hpp"
#include "../inventory_holder/player.hpp"
#include "../valuables/card.hpp"
#include "playerslist.hpp"

#include <iostream>
using namespace std;

/* TODO: set ability -> off
try catch & restoring ability */

AbilityCommand::AbilityCommand(Game* currentGame) : Command(currentGame) {}
Reroll::Reroll(Game* currentGame) : AbilityCommand(currentGame) {}
Quadruple::Quadruple(Game* currentGame) : AbilityCommand(currentGame) {}
Quarter::Quarter(Game* currentGame) : AbilityCommand(currentGame) {}
ReverseDirection::ReverseDirection(Game* currentGame) : AbilityCommand(currentGame) {}
SwapCard::SwapCard(Game* currentGame) : AbilityCommand(currentGame) {}
SwitchCard::SwitchCard(Game* currentGame) : AbilityCommand(currentGame) {}
AbilityLess::AbilityLess(Game* currentGame) : AbilityCommand(currentGame) {}

void Reroll::execute() {
    // Pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru
    Card leftCard, rightCard;
    this->game->mainDeck >> &leftCard;
    this->game->mainDeck >> &rightCard;
    // Setting both cards on player
    this->game->getCurrPlayerRef().setCard(0, leftCard);
    this->game->getCurrPlayerRef().setCard(1, rightCard);
}

void Quadruple::execute() {
    // Pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali lipat
    long int point = this->game->getGamePoint();
    this->game->multiplyGamePoint(4);

    cout << "Quadruple" << endl;
    // cout << currGame.getCurrPlayer().name << "melakukan QUADRUPLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";

}
void Quarter::execute() {
    // Pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat nilai awal.
    long int point = this->game->getGamePoint();
    this->game->multiplyGamePoint(0.25);

    cout << "Quarter" << endl;
    // /* TODO: try catch 
}

void SwapCard::execute() {
    // Menukar kartu pemain lain

    PlayersList optionList;
    // Picking Options
    int firstOption, secondOption;
    Player firstPlayer, secondPlayer;
    // optionList = this->getPlayersList() - optionList[0];
    optionList.print();
    cin >> firstOption;
    // firstPlayer = optionList[firstOption];
    // optionList = this->getPlayersList() - optionList[firstOption];
    optionList.print();
    cin >> secondOption;
    // secondPlayer = optionList[secondOption];

    int firstCard, secondCard;
    cin >> firstCard;
    cin >> secondCard;

    // Swapping Cards
    Card tempCard;
    tempCard = firstPlayer.getCard(firstCard-1);
    firstPlayer.setCard(firstCard-1, secondPlayer.getCard(secondCard-1));
    secondPlayer.setCard(secondCard-1, tempCard);
}

void ReverseDirection::execute() {
    // Memutar arah giliran eksekusi perintah oleh pemain
    this->game->getPlayersListRef().reversePlayers(this->game->getTurnCountInARound());
}

void SwitchCard::execute() {
    // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik pemain lain

    PlayersList optionList;
    // Picking Options
    int option;
    Player targetPlayer;
    // optionList = this->getPlayersList() - optionList[0];
    optionList.print();
    cin >> option;
    // targetPlayer = optionList[option];

    // Swapping Cards
    Card firstCard, secondCard;
    firstCard = targetPlayer.getCard(0);
    secondCard = targetPlayer.getCard(1);

    targetPlayer.setCard(0, this->game->getCurrPlayerRef().getCard(0));
    targetPlayer.setCard(1, this->game->getCurrPlayerRef().getCard(1));
    this->game->getCurrPlayerRef().setCard(0, firstCard);
    this->game->getCurrPlayerRef().setCard(1, secondCard);
}

void AbilityLess::execute() {
    // Mematikan kemampuan lawan

    PlayersList optionList;
    // Picking Options
    int option;
    Player targetPlayer;
    // optionList = this->getPlayersList() - optionList[0];
    // optionList.print();
    cin >> option;
    // targetPlayer = optionList[option];

    // Set Ability Nonactive
    this->game->targetPlayer.setAbilityCardStatus(false);
}