
#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>
using namespace std;

class Randomizer{
public:
    template<typename T>
    void iterShuffle(T array[], int n);

    template<typename T>
    void iterShuffle(T* array);
    
    template<typename T>
    T removeRandom(T* array);

    template<typename T>
    T pickRandom(T* array);
};


template<typename T>
void Randomizer::iterShuffle(T array[], int n) {
    random_device seed;
    mt19937 g(seed());
    shuffle(&array[0], &array[n], g);
}


template<typename T>
void Randomizer::iterShuffle(T* array) {
    random_device seed;
    mt19937 g(seed());
    shuffle(array->begin(), array->end(), g);
}

template<typename T>
T Randomizer::removeRandom(T array[]){
    iterShuffle(array);
    T temp = array->begin();
    *array->erase(array->begin());
    return temp;
}

template<typename T>
T Randomizer::pickRandom(T array[]){
    iterShuffle(array);
    T temp = array->begin();
    return temp;
}

#endif