#include "playerslist.hpp"
#include "../exception/array_exception.hpp"

PlayersList::PlayersList(){};
void PlayersList::addPlayer(Player p) {
    this->list.push_back(p);
}
void PlayersList::changeTurn() {
    this->list.push_back(this->list.front());
    this->list.erase(this->list.begin());
}

void PlayersList::changeRound() {
    this->changeTurn();
}

void PlayersList::print() {
    vector<Player>::iterator i;
    int count = 0;
    
    for (i = this->list.begin(); i < this->list.end(); i++) {
        count++;
        cout << "----------" << count << "----------" << endl;
        (*i).print();
    }
}

PlayersList PlayersList::operator-(const PlayersList& other) {
    /* TODO: tolong ini jelek banget */
    PlayersList diff;
    vector<Player> thisSorted, otherSorted;
    thisSorted = this->list;
    otherSorted = other.list;
    sort(thisSorted.begin(), thisSorted.end());
    sort(otherSorted.begin(), otherSorted.end());

    set_difference(
    thisSorted.begin(), thisSorted.end(),
    otherSorted.begin(), otherSorted.end(),
    back_inserter(diff.list)
    );
}

PlayersList PlayersList::operator-(const Player& other) {
    vector<Player>::iterator res = find(this->list.begin(),this->list.begin(), other);
    if (res != this->list.end()) {
        this->list.erase(res);
    }
}

void PlayersList::reset() {
    sort(this->list.begin(), this->list.end(), [](const Player& p1, const Player& p2) 
                                               {
                                                    return p1.getID() < p2.getID();
                                               });
}

// Winner Evaluator
// vector<Player>::iterator PlayersList::highCard() {
//     vector<Player>::iterator i = this->pq.begin();
//     vector<Player>::iterator maxel = i;
    
//     for (i = this->list.begin() + 1; i < this->list.end(); i++) {
//         maxel = (*i).getCard() > (*maxel).getCard() ? i : maxel; 
//     }
//     return maxel;
// }

Player& PlayersList::getCurrPlayer() {
    if (this->list.size() == 0) {
        throw ArrayIndexInvalid();
    }
    return this->list.front();
}

Player& PlayersList::getPlayerAt(int i) {
    if (i < 0 || i >= this->list.size()) {
        throw ArrayIndexInvalid();
    }
    return this->list[i];
}

void PlayersList::reversePlayers(int turnCount) {
    reverse(this->list.begin(), this->list.end());
    for (int i = 0; i < turnCount - 1; i++) {
        this->changeTurn();
    }
}

int PlayersList::getSize() {
    return this->list.size();
}

PlayersList PlayersList::getNextRound(int turnCount) {
    PlayersList copy = *this;
    int remainingTurns = 8 - turnCount;
    for (int i = 1; i <= remainingTurns; i++) {
        copy.changeTurn();
    }
}

PlayersList PlayersList::getRemainingTurns(int turnCount) {
    PlayersList copy = *this;
    for (int i = 0; i < turnCount; i++) {
        copy.list.pop_back();
    }

    copy.list.erase(copy.list.begin());
    return copy;
}

/* TODO: implement winner searching */
// bool hasWinner();
// Player& findWinner();