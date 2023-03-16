#include "help.hpp"

#include <iostream>
using namespace std;

Help::Help(Game* currentGame) : BasicCommand(currentGame) {}

Help::~Help() {}

void Help::execute() {
    // Interface
    cout << "\033[1m\033[36m \n";
    cout << "HELP COMMAND" << endl;

    cout << "1. NEXT: Tidak melakukan apa-apa" << endl;
    cout << "2. DOUBLE: " << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;
    cout << "HELP COMMAND" << endl;

    cout << "\033[0m";
}