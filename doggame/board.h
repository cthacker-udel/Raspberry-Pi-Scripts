#include "player.h"

typedef struct theBoard{

    char **theboard;
    player *player1;
    player *player2;
    int size;
    char defaultPiece;

}board;

board *makeBoard();

player *getPlayer1(board *);

player *getPlayer2(board *);

int getSize(board *);

char getDefPiece(board *);

void setDefPiece(char, board *);

void makeStartFinish(board *);

void printBoard(board *);

int movePiece(int, player *, board *);


