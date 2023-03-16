
#include "../algos.hpp"
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
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << maxValue(fifth) << endl;

  return 0;
}
  