#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../exception/input_exception.hpp"

#include <string>
#include <iostream>
using namespace std;

class FileHandler {
  private:
    string filename;

  public:
    void setInput(string prompt, string validStrings);

};

#endif