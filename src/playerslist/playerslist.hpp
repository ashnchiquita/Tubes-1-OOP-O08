#ifndef PLAYERSLIST_HPP
#define PLAYERSLIST_HPP

#include "../exception/array_exception.hpp"
#include "../inventory_holder/player.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

template <typename T>
class PlayersList {
    private:
        vector<T> list;
        int turnCountInARound, roundCount;

        void delFirstInsertLast();
        void undoDelFirstInsertLast();

    public:
        PlayersList();
        void addPlayer(T p);
        int getRoundCount() const;
        int getTurnCountInARound() const;
        void changeTurn();
        void undoChangeTurn();
        void changeRound();
        void undoChangeRound();
        void print();
        void printSequence();
        void printSequenceOrder();
        void printSequencePoints();
        
        PlayersList operator-(const T& other);

        T& getCurrPlayer();
        T& getPlayerAt(int i);

        void reversePlayers();
        void afterReverse();
        void reset();
        int getSize();

        PlayersList getNextRound();
        PlayersList getRemainingTurns();

        /* TODO: implement winner searching */
        bool isComplete();
        bool isNextComplete();

        // setelah hadiah dikasih
        T highestPoint() const;
        bool hasWinner() const;
        bool isNewRound() const;
        bool restrictTable() const;
        PlayersList getLeaderboard() const;

        bool restrictCommand() const;
        T& findPlayer(const T& other);
        bool hasAbility() const;
};

template <typename T>
void PlayersList<T>::delFirstInsertLast() {
    this->list.push_back(this->list.front());
    this->list.erase(this->list.begin());
}

template <typename T>
void PlayersList<T>::undoDelFirstInsertLast() {
    this->list.insert(this->list.begin(), this->list.back());
    this->list.erase(this->list.end() - 1);
}

template <typename T>
PlayersList<T>::PlayersList(){
    this->roundCount = 0;
    this->turnCountInARound = 0;
};

template <typename T>
void PlayersList<T>::addPlayer(T p) {
    this->list.push_back(p);
}

template <typename T>
int PlayersList<T>::getRoundCount() const {
    return this->roundCount;
}

template <typename T>
int PlayersList<T>::getTurnCountInARound() const {
    return this->turnCountInARound;
}

template <typename T>
void PlayersList<T>::changeTurn() {
    this->delFirstInsertLast();
    if (this->turnCountInARound == 6) {
        this->changeRound();
    }
    this->turnCountInARound = (this->turnCountInARound + 1) % 7;
}

template <typename T>
void PlayersList<T>::undoChangeTurn() {
    this->turnCountInARound = (this->turnCountInARound + 6) % 7;
    if (this->turnCountInARound == 6) {
        this->undoChangeRound();
    }
    this->undoDelFirstInsertLast();
}

template <typename T>
void PlayersList<T>::changeRound() {
    this->delFirstInsertLast();
    this->roundCount++;
}

template <typename T>
void PlayersList<T>::undoChangeRound() {
    this->undoDelFirstInsertLast();
    this->roundCount--;
}

template <typename T>
void PlayersList<T>::print() {
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

template <typename T>
void PlayersList<T>::printSequence() {
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

template <typename T>
void PlayersList<T>::printSequenceOrder() {
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

template <typename T>
void PlayersList<T>::printSequencePoints() {
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

template <typename T>
PlayersList<T> PlayersList<T>::operator-(const T& other) {
    PlayersList diff = *this;
    vector<Player>::iterator res = find(diff.list.begin(), diff.list.end(), other);

    if (res != diff.list.end()) {
        diff.list.erase(res);
    }

    return diff;
}

template <typename T>
void PlayersList<T>::reset() {
    this->roundCount = 0;
    this->turnCountInARound = 0;
}

template <typename T>
T& PlayersList<T>::getCurrPlayer() {
    if (this->list.size() == 0) {
        throw ArrayIndexInvalidException();
    }
    return this->list.front();
}

template <typename T>
T& PlayersList<T>::getPlayerAt(int i) {
    if (i < 0 || i >= this->list.size()) {
        throw ArrayIndexInvalidException();
    }
    return this->list[i];
}

template <typename T>
void PlayersList<T>::reversePlayers() {
    reverse(this->list.begin(), this->list.end());
    int addCount = (6 + this->turnCountInARound) % 7;
    for (int i = 1; i <= addCount; i++) {
        this->delFirstInsertLast();
    }
}

template <typename T>
void PlayersList<T>::afterReverse() {
    int changePos = (7 - this->turnCountInARound) % 7;
    iter_swap(this->list.begin(), this->list.begin() + changePos);
}

template <typename T>
int PlayersList<T>::getSize() {
    return this->list.size();
}

template <typename T>
PlayersList<T> PlayersList<T>::getNextRound() {
    PlayersList copy = *this;
    int remainingTurns = (8 - this->turnCountInARound) % 7;

    for (int i = 1; i <= remainingTurns; i++) {
        copy.delFirstInsertLast();
    }

    return copy;
}

template <typename T>
PlayersList<T> PlayersList<T>::getRemainingTurns() {
    PlayersList copy = *this;
    for (int i = 0; i < this->turnCountInARound; i++) {
        copy.list.pop_back();
    }

    copy.list.erase(copy.list.begin());
    return copy;
}

template <typename T>
bool PlayersList<T>::isComplete() {
  return this->roundCount == 6 && this->turnCountInARound == 0;
}

template <typename T>
bool PlayersList<T>::isNextComplete() {
    return this->roundCount == 5 && this->turnCountInARound == 6;
}

/* TODO: implement winner searching */
template <typename T>
T PlayersList<T>::highestPoint() const {
    return *(max_element(this->list.begin(), this->list.end()));
}

template <typename T>
bool PlayersList<T>::hasWinner() const {
    return this->highestPoint().getPoint() >= pow(2,32);
}

template <typename T>
PlayersList<T> PlayersList<T>::getLeaderboard() const {
    PlayersList<T> copy = *this;
    sort(copy.list.begin(), copy.list.end(), greater<Player>());
    return copy;
}

template <typename T>
bool PlayersList<T>::restrictCommand() const {
    return this->roundCount < 1;
}

template <typename T>
bool PlayersList<T>::restrictTable() const {
    return this->roundCount > 5;
}

template <typename T>
T& PlayersList<T>::findPlayer(const T& other) {
    vector<Player>::iterator res = find(this->list.begin(), this->list.end(), other);
    if (res != this->list.end()) {
        return *res;
    } else {
        throw ArrayException();
    }
}

template <typename T>
bool PlayersList<T>::isNewRound() const {
    return (this->roundCount != 0 && this->turnCountInARound == 0 );
}

template <typename T>
bool PlayersList<T>::hasAbility() const {
    vector<Player>::const_iterator it;
    for(it = this->list.begin(); it != this->list.end(); ++it) {
        if (it->getAbility().getAbilityCardStatus()) {
            return true;
        }
    }
    return false;
}

#endif