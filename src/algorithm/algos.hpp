
#ifndef ALGOS_H
#define ALGOS_H

#include <random>
using namespace std;

class Algos{
public:
    template<typename T>
    void iterShuffle(T array[], int n);

    template<typename T>
    void iterShuffle(T* array);
    
    template<typename T>
    T removeRandom(T* array);

    template<typename T>
    T pickRandom(T* array);

    template<typename T>
    T maxValue(T* array);
};


template<typename T>
void Algos::iterShuffle(T array[], int n) {
    random_device seed;
    mt19937 g(seed());
    shuffle(&array[0], &array[n], g);
}


template<typename T>
void Algos::iterShuffle(T* array) {
    random_device seed;
    mt19937 g(seed());
    shuffle(array->begin(), array->end(), g);
}

template<typename T>
T Algos::removeRandom(T array[]){
    iterShuffle(array);
    T temp = array->begin();
    *array->erase(array->begin());
    return temp;
}

template<typename T>
T Algos::pickRandom(T array[]){
    iterShuffle(array);
    T temp = array->begin();
    return temp;
}

template<typename T>
T Algos::maxValue(T* array) {
    auto iterate = array->begin();
    T max = *iterate;
    while(iterate != array->end()){
        iterate++;
        T temp = *iterate;
        // if(max =)
    }
    return max;
} 

#endif