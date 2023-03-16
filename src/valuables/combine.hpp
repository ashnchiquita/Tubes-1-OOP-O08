#ifndef COMBINE_HPP
#define COMBINE_HPP

#include "../inventory_holder/table_card.hpp"
#include "../playerslist/playerslist.hpp"

#include <vector>
using namespace std;

class Combine {
    private:
        TableCard tableCard;
        PlayersList playersList;

    public:
        Combine(TableCard table, PlayersList players);
        int evaluate();
};

#endif 