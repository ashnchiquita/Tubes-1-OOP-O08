#include "../input_handler.hpp"

int main() {
  do
  {
    try {
      string validStrings[] = {"Hello", "World"};
      string validStrings2[] = {"Hello2", "World2"};
      string validStrings3[] = {"Hello3", "World3"};
      InputHandler<string> stringHandler;
      stringHandler.setInput("\nTest\n", validStrings, 2);
      cout << stringHandler.getInput();
      
      stringHandler.setInput("\nTest2\n", validStrings2, 2);
      cout << stringHandler.getInput();
      
      stringHandler.setInput("\nTest3\n", validStrings3, 2);
      cout << stringHandler.getInput();
      // InputHandler<int> intHandler;
      // intHandler.setInput("Test\n", 1, 10);
      // cout << intHandler.getInput();
      break;
      
    } catch(InputOutOfRangeException& e) {
      cout << e.what();
    } catch(InputInvalidCharException& e) {
      cout << e.what();
    }
  } while (true);
  

}