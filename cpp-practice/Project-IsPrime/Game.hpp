#include "Player.hpp"


class Game{

    Player player1;
    Player player2;
    int numPlayers;

    public:

        Game();

        Game(string);

        Game(string,string);

        void startGame();

        void displayRules();


};