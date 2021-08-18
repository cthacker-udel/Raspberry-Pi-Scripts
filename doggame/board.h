#include "player.h"

typedef struct theBoard{

    player player1;
    player player2;
    int size;
    char defaultPiece;

}board;

board *makeBoard();

player getPlayer1();

player getPlayer2();

int getSize();

char getDefPiece();

void setDefPiece(char);


