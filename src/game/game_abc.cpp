#include "./game_abc.hpp"

GameABC::GameABC(int playerCount) {
  // Initialization
  string name, filename;
  Card temp;

  // Opening /* TODO: ASCII ART */
  cout << "\033[34m" << "                                ~ , ` - . `* Welcome To *' - . `. ~" << "\033[0m" << endl;

  // cout << "\033[33m"<< "__________________________________________________________________________________________________________" << endl << endl;
  // cout << "|    $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$$\\ $$$$$$\\ $$\\   $$\\       $$$$$$\\ $$$$$$$\\ $$$$$$\\ $$\\   $$\\    |" << endl;
  // cout << "|   $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __ $$\\_$$  _|$$$\\  $$ |      \\_$$  _|$$  __ $$\\_$$  _|$$$\\  $$ |   |" << endl;
  // cout << "|   $$ /  $$ |$$ /  $$ |$$ /  $$ |$$ |  $$ | $$ |  $$$$\\ $$ |        $$ |  $$ |  $$ | $$ |  $$$$\\ $$ |   |" << endl;
  // cout << "|   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$$$$$$  | $$ |  $$ $$\\$$ |        $$ |  $$$$$$$  | $$ |  $$ $$\\$$ |   |" << endl;
  // cout << "|   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$  ____/  $$ |  $$ \\$$$$ |        $$ |  $$  ____/  $$ |  $$ \\$$$$ |   |" << endl;
  // cout << "|   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |       $$ |  $$ |\\$$$ |        $$ |  $$ |       $$ |  $$ |\\$$$ |   |" << endl;
  // cout << "|    $$$$$$  | $$$$$$  | $$$$$$  |$$ |     $$$$$$\\ $$ |\\$$ |      $$$$$$\\  $$ |     $$$$$$\\$$ | \\$$ |    |" << endl;
  // cout << "|    \\______/  \\______/  \\______/ \\__|     \\______|\\__|  \\__|      \\______|\\__|    \\______|\\__|  \\__|    |" << endl;
  // cout << endl <<"__________________________________________________________________________________________________________" << "\033[0m" << endl << endl;
  
  cout << "\033[33m" << "_______________________________________________________________________________________________"<< endl;
  cout << "|                                                                                              |"<< endl;
  cout << "|    ♡♡♡♡♡♡\\   ♡♡♡♡♡♡\\  ♡♡♡♡♡♡♡\\ ♡♡♡♡♡♡\\ ♡♡\\   ♡♡\\       ♡♡♡♡♡♡\\ ♡♡♡♡♡♡♡\\ ♡♡♡♡♡♡\\ ♡♡\\   ♡♡\\    |" << endl;
  cout << "|   ♡♡  __♡♡\\ ♡♡  __♡♡\\ ♡♡  __ ♡♡\\_♡♡  _|♡♡♡\\  ♡♡ |      \\_♡♡  _|♡♡  __ ♡♡\\_♡♡  _|♡♡♡\\  ♡♡ |   |" << endl;
  cout << "|   ♡♡ /  ♡♡ |♡♡ /  ♡♡ |♡♡ |  ♡♡ | ♡♡ |  ♡♡♡♡\\ ♡♡ |        ♡♡ |  ♡♡ |  ♡♡ | ♡♡ |  ♡♡♡♡\\ ♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡♡♡♡♡♡  | ♡♡ |  ♡♡ ♡♡\\♡♡ |        ♡♡ |  ♡♡♡♡♡♡♡  | ♡♡ |  ♡♡ ♡♡\\♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡  ____/  ♡♡ |  ♡♡ \\♡♡♡♡ |        ♡♡ |  ♡♡  ____/  ♡♡ |  ♡♡ \\♡♡♡♡ |   |" << endl;
  cout << "|   ♡♡ |  ♡♡ |♡♡ |  ♡♡ |♡♡ |       ♡♡ |  ♡♡ |\\♡♡♡ |        ♡♡ |  ♡♡ |       ♡♡ |  ♡♡ |\\♡♡♡ |   |" << endl;
  cout << "|    ♡♡♡♡♡♡  | ♡♡♡♡♡♡  |♡♡ |     ♡♡♡♡♡♡\\ ♡♡ | \\♡♡ |      ♡♡♡♡♡♡\\ ♡♡ |     ♡♡♡♡♡♡\\ ♡♡ | \\♡♡ |   |"   << endl;
  cout << "|    \\______/  \\______/ \\__|     \\______|\\__|  \\__|      \\______|\\__|    \\______|\\__|   \\__|   |" << endl;
  cout << "|                                                                                              |"<< endl;
  cout << "|______________________________________________________________________________________________" << "|"<< endl << endl;
  // kata akumah pake foto upin ipin oleng
  
  cout << "\033[34m" << "                         Created by group * ~ ' . * ♡ OOPin 1pin ♡ * . ' ~ * (Kode O08)" << "\033[0m" << endl << endl;

  // Input Source
  CommandHandler<string> optionPicker;
  bool valid = false;
  
  do {
    try {
      cout << "\033[35m";
      optionPicker.yesNoCommand("\nApakah ingin memasukkan konfigurasi deck dari file? [y/n] ");
      cout << "\033[0m";
      string choice = optionPicker.getInput();

      if (choice == "y" || choice == "Y") {
        // Filename
        cout << endl  << "___________________________________________________________" << endl;
        cout          << "| Pastikan file konfigurasi deck berada di folder config. |" << endl;
        cout          << "|_________________________________________________________|" << endl;
        cout << "Masukkan nama file: " << endl << "> ";
        cin >> filename;

        // Get mainDeck
        FileHandler fileHandler;
        mainDeck = fileHandler.colorCodeFromSentence(filename);
      }

      valid = true;
    } catch(Exception& e) {
      cout << e.what() << endl;
    }
  } while (!valid);

  // Config Player
  cin.ignore();

  for (int i = 0; i < playerCount; i++) {
    // Insert name for players
    do {
      cout << "Masukkan nama pemain " << (i + 1) << ": " << endl << "> ";
      getline(cin, name);
      cout << "\n";
    } while (name == "");
    

    // Players get Cards
    this->playersList.addPlayer(Player(name, 0));
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;
    this->mainDeck >> &temp;
    this->playersList.getPlayerAt(i) << temp;

    // Players get Ability
    this->playersList.getPlayerAt(i).getAbilityRef().giveAbility(abilityList[i]);
  }
}