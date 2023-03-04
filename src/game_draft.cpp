#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Player {
    public:
        string name;
        int selfPoint;
        int card;

        Player() : name("halo"), selfPoint(0), card(0) {}
        Player(string nama, int cardNum) : name(nama), selfPoint(0), card(cardNum) {
            cout << "Created player named " << this->name << " and " << this->card << " card." << endl;
        }
        void addPoint(int add) {
            this->selfPoint += add;
        }
        void setCard(int x) {
            this->card = x;
        }
        int getCard() {
            return this->card;
        }
        void print() {
            cout << "Nama : " << this->name << endl;
            cout << "Self Point : " << this->selfPoint << endl;
            cout << "Kartu : " << this->card << endl;
        }
};

class PlayersList {
    public:
        vector<Player> pq;

        PlayersList(){};
        void addPlayer(Player p) {
            this->pq.push_back(p);
        }
        void changeTurn() {
            this->pq.push_back(this->pq.front());
            this->pq.erase(this->pq.begin());
        }
        void changeRound() {
            this->changeTurn();
        }
        void print() {
            vector<Player>::iterator i;
            int count = 0;
            
            for (i = this->pq.begin(); i < this->pq.end(); i++) {
                count++;
                cout << "----------" << count << "----------" << endl;
                (*i).print();
            }
        }
        vector<Player>::iterator highCard() {
            vector<Player>::iterator i = this->pq.begin();
            vector<Player>::iterator maxel = i;
            
            for (i = this->pq.begin() + 1; i < this->pq.end(); i++) {
                maxel = (*i).getCard() > (*maxel).getCard() ? i : maxel; 
            }
            return maxel;
        }
};

class Command {
    public:
        int command;

        Command(int x) : command(x) {};
        void execute(int& gamePoint, PlayersList& pq) {
            switch (this->command)
            {
            case 1: // double
                cout << "Double" << endl;
                gamePoint *= 2;
                break;
            case 2: // half
                cout << "Half" << endl;
                gamePoint = max(1, gamePoint / 2);
                break;
            case 3: // switch front card to 999
                cout << "Switch to 999" << endl;
                pq.pq.front().setCard(999);
                break;
            default: // next
                cout << "Next" << endl;
                break;
            }
        }
};

class Game {
    public:
    int roundCount;
    int turnCountInARound;
    int gamePoint;
    PlayersList pl;

    Game() {
        string name;
        int card;
        cout << "halo selamat dtg" << endl;
        this->roundCount = 0;
        this->turnCountInARound = 0;
        this->gamePoint = 64;
        for (int i = 0; i < 7; i++) {
            cin >> name >> card;
            this->pl.addPlayer(Player(name, card));
        }
    }

    void addRound() {
        this->roundCount++;
    }

    void runTurn() {
        int cmd;
        cout << "It's " << this->pl.pq.front().name << "'s turn!" << endl;
        cout << "Insert command: ";
        cin >> cmd;
        Command com = Command(cmd);
        com.execute(this->gamePoint, this->pl);
        this->pl.changeTurn();
        this->turnCountInARound = (this->turnCountInARound + 1) % 7;
        if (this->turnCountInARound == 0) {
            addRound();
            this->pl.changeTurn();
        }
    }

    void runGame() {
        do {
            printGameState();
            runTurn();
        } while (!this->isFinished());
        this->endGame();
    }

    bool isFinished() {
        return this->roundCount == 6 && this->turnCountInARound == 0;
    }

    void endGame() {
        (*this->pl.highCard()).addPoint(this->gamePoint);
        cout << "the winner is" << endl;
        (*this->pl.highCard()).print();
    }

    void printGameState() {
        cout << "Game Point : " << this->gamePoint << endl;
        cout << "Round Count : " << this->roundCount << endl;
        cout << "Turn Count : " << this->turnCountInARound << endl;
        cout << "Players State" << endl;
        this->pl.print();
    }
};

int main(int argc, const char** argv) {
    Game g;
    g.runGame();
    return 0;
}