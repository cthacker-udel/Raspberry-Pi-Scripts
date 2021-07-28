#include "board.h"

board *newBoard(int x, int y){

    char **newBoard = (char **)malloc((sizeof(char*) * x) * sizeof(char) * y);
    board *theBoard = (board *)malloc(sizeof(board));
    theBoard->theboard = newBoard;
    player *newPlayer1 = createPlayer();
    player *newPlayer2 = createPlayer();
    theBoard->player1 = newPlayer1;
    theBoard->player1 = newPlayer2;
    return theBoard;

}