
#ifndef RANDOMIZER_H
#define RANDOMIZER_H

class randomizer{
public:
    template<typename T>
    void randomize(T* array);
    
    template<typename T>
    T getRandom(T* array);
};

#endif