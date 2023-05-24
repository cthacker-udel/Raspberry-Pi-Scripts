#include "Player.hpp"

class Board{

    int size = 8;
    char **board = new char[size][size];
    Player *player1;
    Player *player2;


    public:

        Board(int);

        Board();

        bool checkPiece(int,int,Player*);

        bool placePiece(int,int,Player*);

        int checkDirection(int,int,int,Player *);


};