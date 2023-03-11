#include "command.hpp"

Command::Command(int x) : command(x) {}
void Command::execute(Game& currGame) {
    switch (this->command)
    {
    case 1: // double
        cout << "Double" << endl;
        currGame.gamePoint *= 2;
        break;
    case 2: // half
        cout << "Half" << endl;
        currGame.gamePoint = max((long int) 1, currGame.gamePoint / 2);
        break;
    case 3: // switch front card to 999
        cout << "Switch to 999" << endl;
        currGame.pl.pq.front().setCard(999);
        break;
    default: // next
        cout << "Next" << endl;
        break;
    }
}