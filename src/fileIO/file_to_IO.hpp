#ifndef FILE_TO_IO_HPP
#define FILE_TO_IO_HPP

#include"../inventory_holder/deck.hpp"
#include "../valuables/card.hpp"
#include "../exception/fileExceptionInterface.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileIO{
    protected:
        static string configPath;
        static string testPath;
    public:
        // config path getter
        static string getConfigPath();

        // test path getter
        static string getTestPath();
    
        // read + create deck from file .txt
        vector<string> FileIO::colorCodeFromSentence(const string& filename);
        
        // get vector of decks
        Deck getDeck();
};

#endif
