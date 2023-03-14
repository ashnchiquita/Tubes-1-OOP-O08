#include "randomizer.hpp"
#include <random>
#include <algorithm>

template<typename T>
void randomizer::shuffle(T* array){
    std::mt19937 g;
    std::shuffle(array.begin(), array.end(), g);
}

template<typename T>
T randomizer::pickRandom(T* array){
    shuffle(array);
    T temp = array.begin();
    array.erase(array.begin());
    return temp;
}
