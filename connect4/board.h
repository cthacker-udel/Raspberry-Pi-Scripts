#include "player.h"

typedef struct theBoard{

    char **theboard;
    int size;
    player *player1;
    player *player2;

}board;


int evalBoard(board*,int,int,int,int);


board *newBoard(int,int);


void displayBoard(board *);

