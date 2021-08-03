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

int evalBoard(board *boardArg,int x,int y, int direction, int player){

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
    int count = 0;


   switch(direction){

        case 1: // North

            currPiece = *(*(arr+x)+y);
            // go farthest behind
            if(x == 0){
<<<<<<< HEAD
                // top of board
=======
                // bottom of board
>>>>>>> refs/remotes/origin/master
                for(int i = x; i < boardArg->size; i++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+y) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+y) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;
            }
            if(y == 0){
                // leftmost side of board
                for(int i = x; i < boardArg->size; i++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+0) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+0) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;
            }
            else{

                for(int i = x; i < boardArg->size; i++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+y) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+y) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;


            }

            break;

        case 2: // North-East

            currPiece = *(*(arr+x)+y);

            if(x == 0){
<<<<<<< HEAD
                // top of board

                // [1][1],[0][2]
                for(int i = x, j = y; i < boardArg->size; i--, j++){
=======
                // bottom of board

                // [0][0],[1][1],[2][2]
                for(int i = x, j = y; i < boardArg->size; i++, j++){
>>>>>>> refs/remotes/origin/master

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;

            }
            if(y == 0){
                // leftmost side of board

                for(int i = x, j = y; i < boardArg->size; i++, j++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }

                }
                return count;

            }
            else{

                for(int i = x, j = y; i < boardArg->size; i++, j++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;

            }


            break;

        case 3: // East

            //currPiece = *(*(arr+x)+y);

            // maintaining same x coord, cycling through y values +1

            if(x == 0){
                // top of board
                for(int i = x, j = y; j < boardArg->size; j++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;
            }
            if(y == 0){
                // leftmost side of board
                // [1,1] -> [1,2] --> x stays the same while y increases

                for(int i = x, j = y; j < boardArg->size; j++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;

            }
            else{

                for(int i = x, j = y; j < boardArg->size; j++){

                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;

            }

            break;

        case 4: // South-East

            //currPiece = *(*(arr+x)+y);

            // x+1, j+1
            if(x == 0){
                // top of board

                for(int i = x, j = y; i < boardArg->size; i++, j++){
                    
                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;

            }
            if(y == 0){
                // leftmost side of board
                // if on leftmost side, and moving south-east, most points could acquire is one

                if(player == 1){
                    count += *(*(boardArg->theboard+x)+y) == boardArg->player1->piece? 1: 0;
                }
                else{
                    count += *(*(boardArg->theboard+x)+y) == boardArg->player2->piece? 1: 0;
                }
                return count;

            }
            else{
                
                // [3,3] -> [4,2] -> x increases while y decreases

                for(int i = x, j = y; i < boardArg->size && y >= 0; j++, y--){
                    
                    if(player == 1){
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player1->piece? 1: 0;
                    }
                    else{
                        count += *(*(boardArg->theboard+i)+j) == boardArg->player2->piece? 1: 0;
                    }

                }
                return count;


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