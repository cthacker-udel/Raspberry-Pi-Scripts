#include "Player.hpp"


class Game{

    Player player1;
    Player player2;


    public:

        Game();

        Game(string);

        Game(string,string);

        void setPlayer1(Player player1);

        void setPlayer2(Player player2);

        void startGame();

};