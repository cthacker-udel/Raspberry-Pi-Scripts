#include "board.h"

int main(void){
    srand(time(NULL)); // seed random generator for initial coin flip
    int theSize;
    printf("\nEnter the size of the board, board will be NxN dimensions : ");
    scanf("%d",&theSize);
    board *iBoard = newBoard(theSize,theSize);
    // board constructed
    printf("\nBoard constructed!");
    displayBoard(iBoard);


    // initialize player turn
    int randNum = rand() % rand();
    int playerTurn;
    // 1 <--- player1, ----> 2 player2

    if(randNum % 2 == 0){
        // player1 turn
        playerTurn = 1;
    }
    else{
        // player2 turn
        playerTurn = 2;
    }

    int x;
    int y;
    int count;

    int compPlay = 0; // false
    do{
        printf("Play against computer?(0 - No, 1 - Yes)");
    }while(scanf("%d",&compPlay));

    while(1){
        // game loop
        if(playerTurn == 1){
            // player1 turn
            printf("\nIt is player1's turn!, place your piece");
            do{
                do{
                    printf("Choose an x coordinate(0 based, inverse directions, x up-down)");
                }while(scanf("%d",&x));
                do{
                    printf("Choose an y coordinate(0 based, inverse direction, y left-right");
                }while(scanf("%d",&y));
            }while(placePiece(x,y,iBoard,0,iBoard->player1->piece));
            placePiece(x,y,1,iBoard,iBoard->player1->piece);
            for(int i = 1; i <= 8; i++){
                char *direction = i == 1? "North": i == 2? "North-East": i == 3? "East": i == 4? "South-East": i == 5? "South": i == 6? "South-West": i == 7? "West": "North-West";
                count = evalBoard(iBoard,x,y,i,1);
                if(count >= 4){
                    printf("\nPlayer1 wins!");
                    break;
                }
                else{
                    printf("\nYour placement has %d points in the %s direction",count,direction);
                }
            }
        }
        if(playerTurn == 2){
            // player2 turn
        }
        break;



    }

}

