
#ifndef MAXVAL_H
#define MAXVAL_H

using namespace std;

class MaxVal{
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

#endif