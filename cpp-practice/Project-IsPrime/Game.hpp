#include "Player.hpp"


class Game{

    Player player1;
    Player player2;
    int numPlayers;
    bool turn;

    public:

        Game();

        Game(string);

        Game(string,string);

        void startGame();

        void displayRules();

        void displayPrompt();

        void correctAnswer();

        void incorrectAnswer();

        void correctComputerAnswer();

        void incorrectComputerAnswer();

        void startGame();

        bool isPrime(int);


};