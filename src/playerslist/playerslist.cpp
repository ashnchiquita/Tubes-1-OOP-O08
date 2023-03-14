#include "playerslist.hpp"
// #include "../exception/array_exception.hpp"

void PlayersList::delFirstInsertLast() {
    this->list.push_back(this->list.front());
    this->list.erase(this->list.begin());
}

PlayersList::PlayersList(){
    this->roundCount = 0;
    this->turnCountInARound = 0;
};

void PlayersList::addPlayer(Player p) {
    this->list.push_back(p);
}

int PlayersList::getRoundCount() const {
    return this->roundCount;
}

int PlayersList::getTurnCountInARound() const {
    return this->turnCountInARound;
}

void PlayersList::changeTurn() {
    this->delFirstInsertLast();
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
    if (this->turnCountInARound == 0 && this->roundCount != 0) {
        this->changeRound();
  }
}

void PlayersList::changeRound() {
    this->delFirstInsertLast();
    this->roundCount++;
}

void PlayersList::print() {
    cout << "Round Count: " << this->roundCount << endl;
    cout << "Turn Count In A Round: " << this->turnCountInARound << endl;
    cout << "Players Sequence: ";
    this->printSequence();
}

void PlayersList::printSequence() {
    if (this->getSize() == 0) {
        cout << "-" << endl;
    } else {
        vector<Player>::iterator i = this->list.begin();
        cout << (*i).getName();
        for (i = this->list.begin() + 1; i < this->list.end(); ++i) {
            cout << ", " << (*i).getName();
        }
        cout << endl;
    }
}

void PlayersList::printSequenceOrder() {
    if (this->getSize() == 0) {
        cout << "Tidak ada Player" << endl;
    } else {
        vector<Player>::iterator i;
        int count = 1;
        for (i = this->list.begin(); i != this->list.end(); ++i) {
            cout << count << ". " << (*i).getName() << endl;
            count++;
        }
    }
}

PlayersList PlayersList::operator-(const Player& other) {
    PlayersList diff = *this;
    vector<Player>::iterator res = find(diff.list.begin(), diff.list.end(), other);

    if (res != diff.list.end()) {
        diff.list.erase(res);
    }

    return diff;
}

void PlayersList::reset() {
    this->roundCount = 0;
    this->turnCountInARound = 0;
}

Player& PlayersList::getCurrPlayer() {
    // if (this->list.size() == 0) {
    //     throw ArrayIndexInvalid();
    // }
    return this->list.front();
}

Player& PlayersList::getPlayerAt(int i) {
    // if (i < 0 || i >= this->list.size()) {
    //     throw ArrayIndexInvalid();
    // }
    return this->list[i];
}

void PlayersList::reversePlayers() {
    reverse(this->list.begin(), this->list.end());
    int addCount = (6 + this->turnCountInARound) % 7;
    for (int i = 1; i <= addCount; i++) {
        this->delFirstInsertLast();
    }
}

int PlayersList::getSize() {
    return this->list.size();
}

PlayersList PlayersList::getNextRound() {
    PlayersList copy = *this;
    int remainingTurns = (8 - this->turnCountInARound) % 7;
    for (int i = 1; i <= remainingTurns; i++) {
        copy.delFirstInsertLast();
    }

    return copy;
}

PlayersList PlayersList::getRemainingTurns() {
    PlayersList copy = *this;
    for (int i = 0; i < this->turnCountInARound; i++) {
        copy.list.pop_back();
    }

    copy.list.erase(copy.list.begin());
    return copy;
}

bool PlayersList::isComplete() {
  return this->roundCount == 6 && this->turnCountInARound == 0;
}

/* TODO: implement winner searching */
Player PlayersList::highestPoint() const {
    return *(max_element(this->list.begin(), this->list.end()));
}

bool PlayersList::hasWinner() const {
    return this->highestPoint().getPoint() >= pow(2,32);
}

PlayersList PlayersList::getLeaderboard() const {
    PlayersList copy = *this;
    sort(copy.list.begin(), copy.list.end(), greater<Player>());
    return copy;
}

bool  PlayersList::restrictCommand() const {
    return (this->roundCount < 1);
}