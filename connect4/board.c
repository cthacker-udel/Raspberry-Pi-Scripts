#include "board.h"

board *newBoard(int x, int y){
    
    if(x != y){
        printf("\nMatrix must be same dimensions\n");
        return NULL;
    }

    char **newBoard = (char **)malloc((sizeof(char*) * x) * sizeof(char) * y);
    board *theBoard = (board *)malloc(sizeof(board));
    theBoard->size = x;
    theBoard->theboard = newBoard;
    player *newPlayer1 = createPlayer();
    player *newPlayer2 = createPlayer();
    theBoard->player1 = newPlayer1;
    theBoard->player1 = newPlayer2;
    return theBoard;

}

int evalBoard(board *boardArg,int x,int y, int direction){

    /*

        1) North
        2) North-East
        3) East
        4) South-East
        5) South
        6) South-West
        7) West
        8) North-West


    */


    


}