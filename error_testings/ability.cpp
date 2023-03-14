#include "../src/inventory_holder/player.hpp"
#include <iostream>
using namespace std;

/* STATUS : SOLVED */

// run script ini berkali2, coba pake setter nya, terus uncomment lagi
// command: g++ -o ability ability.cpp ../src/valuables/card.cpp ../src/inventory_holder/player.cpp

int main() {
    Player p1("chi", 10);
    p1.print();
    p1.setAbilityType(AbilityType::QUARTER);
    p1.print();
    return 0;
}

/* TESTER LOG */
/*

 * CHI (14/03/2023 04.50)
   Ability yang keluar selalu sama, gapernah bisa Ability NULLABILITY

   Possible causes
   https://forums.unrealengine.com/t/adding-to-existing-c-enum-does-not-update-blueprints-using-the-enum/386686/3

   solution (yg bs diusulin): pake map string aja, enum c++ emang ngebug sepertinya
   
   UPDATE: solved, ternyata ada yang kelupaan aja di konstruktor player

*/
