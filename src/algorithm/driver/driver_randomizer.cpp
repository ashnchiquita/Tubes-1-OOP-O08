
#include "../algos.hpp"
#include "../randomizer.hpp"
#include <iostream>
#include <random>
#include <algorithm>

int abilityList[8] = {1,2,3,4,5,6,7,8};

int main() {
  Algos r;
  r.iterShuffle(abilityList, 8);
  
  for(int i = 0; i < 8; i++){
    std::cout << abilityList[i] << std::endl;
  }

  vector<int> test(6,42);

  cout << maxValue(test);

  return 0;
}
  