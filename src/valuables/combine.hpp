#ifndef COMBINE_HPP
#define COMBINE_HPP

#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"
#include "../inventory_holder/player_poker.hpp"

#include <vector>
using namespace std;

class Combine {
    private:
        TableCard tableCard;
        PlayersList<PlayerPoker> playersList;

    public:
        Combine(TableCard table, PlayersList<PlayerPoker> players);
        int evaluate();
};

#endif 