#include "ability_command.hpp"
#include "../inventory_holder/player.hpp"
#include "../valuables/card.hpp"
#include "playerslist.hpp"

#include <iostream>
using namespace std;

/* TODO: set ability -> off
try catch & restoring ability */

AbilityCommand::AbilityCommand() {}

void Reroll::execute(Game& currGame) {
    // Pemain membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru
    // currGame.getCurrPlayerRef().setCards(getTwoFromDeck());
}

void Quadruple::execute(Game& currGame) {
    // Pemain akan menaikkan total poin hadiah pada permainan menjadi empat kali lipat

    long int point = currGame.getGamePoint();
    cout << "Quadruple" << endl;
    currGame.multiplyGamePoint(4);
    // cout << currGame.getCurrPlayer().name << "melakukan QUADRUPLE!" << endl;
    // cout << "Poin hadiah naik dari " << point << " menjadi curr.gamePoint!";
}

void Quarter::execute(Game& currGame) {
    // Pemain akan menurunkan total poin hadiah pada permainan menjadi seperempat nilai awal.
    long int point = currGame.getGamePoint();

    cout << "Quarter" << endl;
    // try
    currGame.multiplyGamePoint(0.25);
    // cout << currGame.getCurrPlayer().name << "melakukan QUARTER!" << endl;

    // catch(err){
    //     cout << "Sayangnya poin hadiah sudah bernilai " << curr.gamePoint << ". Poin hadiah tidak berubah.. Giliran dilanjut!"
    // }
    // cout << "Poin hadiah turun dari " << point << " menjadi curr.gamePoint!";
    
}

void ReverseDirection::execute(Game& currGame) {
    // Memutar arah giliran eksekusi perintah oleh pemain
    currGame.getPlayersListRef().reversePlayers(currGame.getTurnCountInARound());
}

void SwapCard::execute(Game& currGame) {
    // Menukar satu kartu pemain lain dengan satu kartu pemain yang lain.
    // Player player1, player2;
    // Card card1, card2;
    // PlayersList exPlayer;
    
    // exPlayer.addPlayer(currGame.getCurrPlayer());
    // cout << Silahkan pilih pemain yang kartunya ingin anda tukar: << endl;
    // cout << (currGame.getPlayersList() - exPlayer);
    // cin << player1;
    // exPlayer.addPlayer(player1);
    // insert dirinya ke player1

    // cout << Silahkan pilih pemain yang kartunya ingin anda tukar: << endl;
    // printAllPlayers() - dirinya - player1
    // cin << player2

    // cout << "Silakan pilih kartu kanan/kiri" << player1 << endl;
    // cin << option1;

    // cout << "Silakan pilih kartu kanan/kiri" << player2 << endl;
    // cin << option2;

    // Card1 = option == 1 ? player1.getFirstCard() : player1.getSecondCard();
    // Card2 = option == 1 ? player2.getFirstCard() : player2.getSecondCard();

    // player1.setKiri(Card2)
    // player2.setKiri(Card1)
}

void SwitchCard::execute(Game& currGame) {
    // Pemain akan menukar kartu main deck miliknya dengan kartu main deck milik pemain lain

    // Player targetPlayer
    // cin << targetPlayer                  // mau card siapa?
    // temp1 = getCurrPlayer().getAllCards()
    // temp2 = targetPlayer.getAllCards()

    // currentPlayer.setCards()             // tapi ini ga oop hm
    // targetPlayer.setCards()
    

    // int idx11 = rand() % 7;
    // int idx21 = rand() % 7;
    // int idx12 = rand() % 7;
    // int idx22 = rand() % 7;

    // InventoryHolder temp = pc1[idx11];
    // pc1[idx11] = pc2[idx21];
    // pc2[idx21] = temp;

    // InventoryHolder temp = pc1[idx12];
    // pc1[idx12] = pc2[idx22];
    // pc2[idx22] = temp;
    //nuker 2 kartu diri sendiri dgn pemain lain
}

void Abilityless::execute(Game& currGame) {
    // set ability card false
}