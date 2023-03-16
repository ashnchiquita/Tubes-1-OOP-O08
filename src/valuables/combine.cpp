#include "combine.hpp"
#include "combo.hpp"

Combine::Combine(TableCard table, PlayersList players) {
    this->tableCard = table;
    this->playersList = players;
}

int Combine::evaluate() {
    vector<Card> tableCard, maxComboCards, combinedCards; // max panjangnya 5

    int nPlayers = this->playersList.getSize();
    vector< vector<Card> > playerHands(nPlayers); // ini panjangnya 7

    tableCard = this->tableCard.getAllCards();

    for (int i = 0; i < nPlayers; i++) {
        playerHands[i] = this->playersList.getPlayerAt(i).getAllCards();
    }
    
    // Initialization
    int winningPlayerIdx = 0;
    combinedCards = tableCard;
    
    Combo tempCombo(combinedCards);
    int highestCombo = tempCombo.value();

    maxComboCards = combinedCards;

    // Find a player with the highest combo
    // C(5, 4) * C(2, 1)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                combinedCards[j] = tableCard[j];
            }
        }

        for (int j = 0; j < nPlayers; j++) {
            combinedCards[i] = playerHands[j][0];
            tempCombo = Combo(combinedCards);

            if (tempCombo.value() > highestCombo) {
                highestCombo = tempCombo.value();
                winningPlayerIdx = j;
                maxComboCards = combinedCards;
            }

            combinedCards[i] = playerHands[j][1];
            tempCombo = Combo(combinedCards);

            if (tempCombo.value() > highestCombo) {
                highestCombo = tempCombo.value();
                winningPlayerIdx = j;
                maxComboCards = combinedCards;
            }
        }
    }

    // C(5, 3) * C(2, 2)
    do {
        for (int i = 0; i < nPlayers; i++) {
            // bagian yang sebelumnya salah(?)
            combinedCards = playerHands[i];
            combinedCards.insert(combinedCards.end(), tableCard.begin(), tableCard.begin() + 3);

            tempCombo = Combo(combinedCards);

            if (tempCombo.value() > highestCombo) {
                highestCombo = tempCombo.value();
                winningPlayerIdx = i;
                maxComboCards = combinedCards;
            }
        }
    } while (next_permutation(tableCard.begin(), tableCard.end()));
    
    Player& winningPlayer = this->playersList.getPlayerAt(winningPlayerIdx);

    /* DEBUG */
    cout << "Combo " << winningPlayer.getName() << ": " << endl;
    for (int i = 0; i < 5; i++) {
        maxComboCards[i].displayCard();
        cout << endl;
    }

    return winningPlayerIdx;
}