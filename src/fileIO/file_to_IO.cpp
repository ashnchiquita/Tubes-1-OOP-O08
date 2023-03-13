#include "file_to_IO.hpp"
#include <filesystem>
#include <sstream>

using namespace std;

string FileIO::configPath = "./config";
string FileIO::testPath = "./tests";

// get folder config path
string FileIO::getConfigPath(){
    return FileIO::configPath;
}

// get tests config path
string FileIO::getTestPath(){
  return FileIO::testPath;
}

// hasil: vektor <M6, M7, K1>
vector<string> FileIO::colorCodeFromSentence(const string& filename) {
  vector<string> colorCodes;
  string line;
  ifstream file(filename);

  try {
    if (file.is_open()) {
      while (getline(file, line)) {
        istringstream iss(line);
        string color, number;
        iss >> color >> number;
        colorCodes.push_back(color + number);
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
