
#ifndef RANDOMIZER_H
#define RANDOMIZER_H

//ini jadinya gimana kemaren?
class randomizer{
public:
    template<typename T>
    void shuffle(T* array);
    
    template<typename T>
    T pickRandom(T* array);
};

#endif