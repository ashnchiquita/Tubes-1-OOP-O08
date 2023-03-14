#include "input_handler.hpp"

template <typename T>
void InputHandler<T>::setInput(string prompt, string validStrings[], int countValid) {
  cout << prompt;

  string temp;
  cin >> temp;
  
  bool isIn = false;
  int i = 0;
  while(i < countValid && !isIn) {
    if(temp == validStrings[i]) {
      isIn = true;
    }
    i++;
  }

  if(!isIn) {
    throw InputOutOfRangeException();
  }

  this->input = temp;
}

template <typename T>
void InputHandler<T>::setInput(string prompt, int minRange, int maxRange) {
  cout << prompt;

  string temp;
  cin >> temp;

  for(char c: temp) {
    int x = (int) c - (int) '0';
    if(x < 0 || x > 9) {
      throw InputInvalidCharException();
    }
  }

  int y = stoi(temp);
  if(y < minRange || y > maxRange) {
    throw InputOutOfRangeException();
  }

  this->input = y;
}

template <typename T>
T InputHandler<T>::getInput() const {
  return this->input;
}