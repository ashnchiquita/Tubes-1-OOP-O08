#include <string>
using namespace std;
// maaf masih disatuin gwah masih bingung xixix
/* just to hide error squiggles */
class Player {

};

class PlayersQueue {

};

class Deck {

};

class Turn {
    private:
        static int turnCountInARound;
        Player currPlayer;

    public:
        Turn(Player currentPlayer); /* prob: how to make attr as reference? */
        Player& getCurrPlayer();
        void runTurn();
        /* will look like 
        input (command)
        determine command type
        this->currPlayer.execute(command) & validation */
};

class Round {
    private:
        static int roundCount;
        static PlayersQueue playerQueue;
        Turn currTurn;

    public:
        Round();
        static int getRoundCount();
        void changeCurrTurn();
};

class Game {
    private:
        static int roundCount;
        Player p1, p2, p3, p4, p5, p6, p7;
        static int currGamePoint;
        Round currRound;
        Deck cardDeck;

    public:
        Game();
        Game(string configFilePath);
        void changeCurrRound();
};