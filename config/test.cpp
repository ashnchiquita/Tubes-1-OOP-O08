#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream configFile("asumsi.txt");
  string cardLine, token;

  while(getline(configFile, cardLine, ' ')){
    cout << cardLine << endl;
  }

  // cari kartu ada gak di deck

  // push back kartu
  return 0;
}