#include "playerslist.hpp"

PlayersList::PlayersList(){};
void PlayersList::addPlayer(Player p) {
    this->pq.push_back(p);
}
void PlayersList::changeTurn() {
    this->pq.push_back(this->pq.front());
    this->pq.erase(this->pq.begin());
}
void PlayersList::changeRound() {
    this->changeTurn();
}
void PlayersList::print() {
    vector<Player>::iterator i;
    int count = 0;
    
    for (i = this->pq.begin(); i < this->pq.end(); i++) {
        count++;
        cout << "----------" << count << "----------" << endl;
        (*i).print();
    }
}
vector<Player>::iterator PlayersList::highCard() {
    vector<Player>::iterator i = this->pq.begin();
    vector<Player>::iterator maxel = i;
    
    for (i = this->pq.begin() + 1; i < this->pq.end(); i++) {
        maxel = (*i).getCard() > (*maxel).getCard() ? i : maxel; 
    }
    return maxel;
}