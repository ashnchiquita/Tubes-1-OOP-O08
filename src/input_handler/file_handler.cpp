#include "file_handler.hpp"
#include "../valuables/card.hpp"
#include "../exception/config_exception.hpp"

#include <fstream>
#include <sstream>
using namespace std;

string FileHandler::configPath = "../config/";
string FileHandler::testPath = "../tests/";

// get folder config path
string FileHandler::getConfigPath() { return FileHandler::configPath; }

// get tests config path
string FileHandler::getTestPath() { return FileHandler::testPath; }

// e.g, file.txt:
// M 6
// M 7
// K 1
// hasil: vektor <M6, M7, K1>
vector<Card> FileHandler::colorCodeFromSentence(const string& filename) {
  vector<Card> colorCodes;
  string line;
  string path = configPath + filename;
  ifstream file(path);

  if (file.is_open()) {
    while (getline(file, line)) {

      istringstream iss(line);
      string color, number;
      iss >> color >> number;
      // colorCodes.push_back(color + number);
      CardColor warna;
      if (color == "M") {
        warna = CardColor::RED;
      } else if (color == "H") {
        warna = CardColor::GREEN;
      } else if (color == "B") {
        warna = CardColor::BLUE;
      } else if (color == "K") {
        warna = CardColor::YELLOW;
      }
      colorCodes.push_back(*(new Card(stoi(number), warna)));
    }
    file.close();

  }
  else {
    colorCodes.clear();
    throw ConfigFileException();
  }

  return colorCodes;
}
