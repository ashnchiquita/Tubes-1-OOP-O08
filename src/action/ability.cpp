#include "ability.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool AbilityCmd::isAbilityless(){
    return checkAbilityLess;
}

void Reroll::execute(InventoryHolder &p){
    p.removeCard(); //asumsi 1x removeCard() cmn remove 1
    p.removeCard();

    p.addCard(); //asumsi 1x addCard hny add 1 kartu
    p.addCard();
}

void Quadruple::execute(double points){
    if (points > 1){
        points *= 4;
    }
}

void Quarter::execute(double points){
    if (points > 1){
        points *= 0.25;
    }
}

/*void ReverseDirection::reverseArray(PlayersQueue p1[], int start, int end){
    start = 0;
    end = 6;
    while (start < end){
        int temp = p1[start];
        p1[start] = p1[end];
        p1[end] = temp;
        start++;
        end--;
    }
}*/

void ReverseDirection::execute(PlayersQueue pq[], int ccplayer){
    reverseArray(pq, ccplayer + 1, 6);
    reverseArray(pq, 0, ccplayer -1);
    reverseArray(pq, 0, ccplayer-1);

    PlayersQueue temp = pq[0];
    pq[0] = pq[7-1];
    pq[7-1] = temp;
}

void SwapCard::execute(InventoryHolder pc1[], InventoryHolder pc2[]){
    int idx1 = rand() % 7;
    int idx2 = rand() % 7;

    InventoryHolder temp = pc1[idx1];
    pc1[idx1] = pc2[idx2];
    pc2[idx2] = temp;
    //nuker 1 kartu 2 pemain lain

}

void SwitchCard::execute(InventoryHolder pc1[], InventoryHolder pc2[]){
    int idx11 = rand() % 7;
    int idx21 = rand() % 7;
    int idx12 = rand() % 7;
    int idx22 = rand() % 7;

    InventoryHolder temp = pc1[idx11];
    pc1[idx11] = pc2[idx21];
    pc2[idx21] = temp;

    InventoryHolder temp = pc1[idx12];
    pc1[idx12] = pc2[idx22];
    pc2[idx22] = temp;    
    //nuker 2 kartu diri sendiri dgn pemain lain
}

void AbilityLess::execute(){
    checkAbilityLess = true;
}