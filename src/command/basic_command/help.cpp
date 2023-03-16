#include "help.hpp"

#include <iostream>
using namespace std;

Help::Help(GamePoker* currentGame) : BasicCommand(currentGame) {}

Help::~Help() {}

void Help::execute() {
    // Interface
    cout << "\033[1m\033[36m \n";
    cout << "---------------------------------*** COMMANDS GUIDE ***---------------------------------" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|                              ----* BASIC COMMANDS *----                              |" << endl;
    cout << "|                              Dapat dipanggil kapan saja                              |" << endl;
    cout << "|   NEXT         : Tidak melakukan apa-apa                                             |" << endl;
    cout << "|   DOUBLE       : Mengalikan poin pada meja menjadi dua kali lipat                    |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|                             ----* ABILITY COMMANDS *----                             |" << endl;
    cout << "|             Dapat dipanggil jika memiliki kartu ability yang bersesuaian             |" << endl;  
    cout << "|   HALF         : Mengalikan poin pada meja menjadi setengah kali lipat               |" << endl;
    cout << "|   REROLL       : Mengambil ulang 2 kartu                                             |" << endl;
    cout << "|   QUARTER      : Mengalikan poin pada meja menjadi seperempat kali lipat             |" << endl;
    cout << "|   QUADRUPLE    : Mengalikan poin pada meja menjadi empat kali lipat                  |" << endl;
    cout << "|   ABILITYLESS  : Mematikan kartu ability milik player lain                           |" << endl;
    cout << "|   REVERSE      : Memutar arah giliran                                                |" << endl;
    cout << "|   SWAPCARD     : Menukar 1 kartu milik pemain lain dengan 1 kartu pemain lainnya     |" << endl;
    cout << "|   SWITCH       : Menukar 2 kartu milik sendiri dengan pemain lain                    |" << endl;
    cout << "|   HELP         : Memberikan list command yang dapat diberikan                        |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    cout << "\033[0m";
}