#include "Player.hpp"

class Board{

    int size = 8;
    char **board = new char[size][size];
    Player *player1;
    Player *player2;


    public:

        Board(int);

        Board();


};