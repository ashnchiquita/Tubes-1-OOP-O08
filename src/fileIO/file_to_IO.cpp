#include "file_to_IO.hpp"

#include <filesystem>
#include <sstream>

#include "../valuables/card.hpp"

using namespace std;

string FileIO::configPath = "./config";
string FileIO::testPath = "./tests";

// get folder config path
string FileIO::getConfigPath() { return FileIO::configPath; }

// get tests config path
string FileIO::getTestPath() { return FileIO::testPath; }

// e.g, file.txt:
// M 6
// M 7
// K 1
// hasil: vektor <M6, M7, K1>
vector<Card> FileIO::colorCodeFromSentence(const string& filename) {
  vector<Card> colorCodes;
  string line;
  ifstream file(filename);

  try {
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
    } else {
      throw runtime_error("Error opening file: " + filename);
    }
  } catch (const exception& e) {
    cerr << "Exception: " << e.what() << endl;
    // handling empty vector
    colorCodes.clear();
  }

  return colorCodes;
}
