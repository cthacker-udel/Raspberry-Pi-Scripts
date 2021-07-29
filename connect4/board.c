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

    // filling out board with base-values

    for(int i = 0; i < theBoard->size; i++){

        for(int j = 0; j < theBoard->size; j++){

            *(*(theBoard->theboard+i)+j) = '?';

        }

    }

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

    char **arr = boardArg->theboard;
    char currPiece;


   switch(direction){

        case 1: // North

            currPiece = *(*(arr+x)+y);
            // go farthest behind
            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }

            break;

        case 2: // North-East

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }


            break;

        case 3: // East

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }

            break;

        case 4: // South-East

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }


            break;

        case 5: // South

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }

            break;

        case 6: // South-West

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }

            break;

        case 7: // West

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }


            break;

        case 8: // North-West

            currPiece = *(*(arr+x)+y);

            if(x == 0){
                // bottom of board
            }
            if(y == 0){
                // leftmost side of board
            }


            break;

        default:
            printf("\n-=-=-= ERROR : INVALID INPUT -=-=-=\n");
            // reached default case
            break;


   }






}