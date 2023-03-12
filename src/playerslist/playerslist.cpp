#include "playerslist.hpp"

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
    return this->list.front();
}

void PlayersList::reversePlayers(int turnCount) {
    reverse(this->list.begin(), this->list.end());
    for (int i = 0; i < turnCount - 1; i++) {
        this->changeTurn();
    }
}

/* TODO: implement winner searching */
// bool hasWinner();
// Player& findWinner();