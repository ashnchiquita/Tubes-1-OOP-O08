#ifndef Algos_H
#define Algos_H

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
T maxValue(vector <T> array) {
    T temp = *array->begin();
    vector <T>::iterator it;
    for (it = array.begin(); it != array.end(); ++it) {
        if (it > temp){
            temp = it;
        }
    }
    return temp;
} 
#endif