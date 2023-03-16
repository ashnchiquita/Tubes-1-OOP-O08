#include "playerslist.hpp"
#include "../exception/array_exception.hpp"

void PlayersList::delFirstInsertLast() {
    this->list.push_back(this->list.front());
    this->list.erase(this->list.begin());
}

void PlayersList::undoDelFirstInsertLast() {
    this->list.insert(this->list.begin(), this->list.back());
    this->list.erase(this->list.end() - 1);
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

void PlayersList::resetPlayersCards() {
    for (int i=0; i<getSize(); i++){
        this->list[i].clearCards();
    }
}

void PlayersList::changeTurn() {
    this->delFirstInsertLast();
    if (this->turnCountInARound == 6) {
        this->changeRound();
    }
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
}

void PlayersList::undoChangeTurn() {
    this->turnCountInARound = (this->turnCountInARound + 6) % 7;
    if (this->turnCountInARound == 6) {
        this->undoChangeRound();
    }
    this->undoDelFirstInsertLast();
}

void PlayersList::changeRound() {
    this->delFirstInsertLast();
    this->roundCount++;
}

void PlayersList::undoChangeRound() {
    this->undoDelFirstInsertLast();
    this->roundCount--;
}

void PlayersList::print() {
    char space = ' ';
    char dash = '-';
    int num = 60;
    cout << "| Round Count: " << this->roundCount << string(num-sizeof(this->roundCount)-15, space) << "|" << endl;
    cout << "| Turn Count In A Round: " << this->turnCountInARound << string(num-sizeof(this->turnCountInARound)-26, space) << "|" << endl;
    cout << "| Players Sequence: ";
    if (this->getSize() == 0) {
        cout << "-" << endl;
    } else {
        vector<Player>::iterator i = this->list.begin();
        cout << (*i).getName();
        for (i = this->list.begin() + 1; i < this->list.end(); ++i) {
            cout << ", ";
            (*i).print();
        }
        cout << endl;
    }
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

void PlayersList::printSequencePoints() {
    if (this->getSize() == 0) {
        cout << "Tidak ada Player" << endl;
    } else {
        vector<Player>::iterator i;
        int count = 1;
        for (i = this->list.begin(); i != this->list.end(); ++i) {
            cout << count << ". " << (*i).getName() << ": " << (*i).getPoint() << endl;
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
    if (this->list.size() == 0) {
        throw ArrayIndexInvalidException();
    }
    return this->list.front();
}

Player& PlayersList::getPlayerAt(int i) {
    if (i < 0 || i >= this->list.size()) {
        throw ArrayIndexInvalidException();
    }
    return this->list[i];
}

void PlayersList::reversePlayers() {
    reverse(this->list.begin(), this->list.end());
    int addCount = (6 + this->turnCountInARound) % 7;
    for (int i = 1; i <= addCount; i++) {
        this->delFirstInsertLast();
    }
}

void PlayersList::afterReverse() {
    int changePos = (7 - this->turnCountInARound) % 7;
    iter_swap(this->list.begin(), this->list.begin() + changePos);
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

bool PlayersList::isNextComplete() {
    return this->roundCount == 5 && this->turnCountInARound == 6;
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

bool PlayersList::restrictCommand() const {
    return this->roundCount < 1;
}

bool PlayersList::restrictTable() const {
    return this->roundCount > 5;
}

Player& PlayersList::findPlayer(const Player& other) {
    vector<Player>::iterator res = find(this->list.begin(), this->list.end(), other);
    if (res != this->list.end()) {
        return *res;
    } else {
        throw ArrayException();
    }
}

bool PlayersList::isNewRound() const {
    return (this->roundCount != 0 && this->turnCountInARound == 0 );
}

bool PlayersList::hasAbility() const {
    vector<Player>::const_iterator it;
    for(it = this->list.begin(); it != this->list.end(); ++it) {
        if (it->getAbility().getAbilityCardStatus()) {
            return true;
        }
    }
    return false;
}