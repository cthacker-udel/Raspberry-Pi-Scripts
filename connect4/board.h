#include "player.h"

typedef struct theBoard{

    char theboard[1][1];
    player player1;
    player player2;

}board;


int evalBoard(board);


board *newBoard(int,int);

