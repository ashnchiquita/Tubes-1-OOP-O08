#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../exception/input_exception.hpp"

#include <string>
#include <iostream>
using namespace std;

template <typename T>
class InputHandler {
  private:
    T input;

  public:
    void setInput(string prompt, string validStrings[], int countValid);
    void setInput(string prompt, int minRange, int maxRange);
    T getInput() const;
};

#endif