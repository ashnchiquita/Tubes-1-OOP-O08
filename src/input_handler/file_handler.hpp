#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

//#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../exception/config_exception.hpp"
#include "../inventory_holder/deck.hpp"
#include "../valuables/card.hpp"

class FileHandler {
 protected:
  static string configPath;
  static string testPath;

 public:
  // config path getter
  static string getConfigPath();

  // test path getter
  static string getTestPath();

  // read + create deck from file .txt
  vector<Card> colorCodeFromSentence(const string& filename);

  // get vector of decks
  Deck getDeck();
};

#endif
