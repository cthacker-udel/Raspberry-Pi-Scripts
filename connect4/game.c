#include "board.h"

int main(void){
    srand(time(NULL)); // seed random generator for initial coin flip
    int theSize;
    printf("\nEnter the size of the board, board will be NxN dimensions : ");
    scanf("%d",&theSize);
    board *iBoard = newBoard(theSize,theSize);
    // board constructed
    printf("\nBoard constructed!\n");
    displayBoard(iBoard);


    // initialize player turn
    int randNum = rand() % rand();
    int playerTurn;
    // 1 <--- player1, ----> 2 player2
    
    playerTurn = 1; // debugging purposes
    /*
    if(randNum % 2 == 0){
        // player1 turn
        playerTurn = 1;
    }
    else{
        // player2 turn
        playerTurn = 2;
    }
    *///debugging purposes

    int x;
    int y;
    int count;

    int compPlay = 0; // false
    do{
        printf("Play against computer?(0 - No, 1 - Yes)");
    }while(scanf("%d",&compPlay) == 0);

    printf("\nBefore while loop\n");

    while(1){
        // game loop
        displayBoard(iBoard);
        if(playerTurn == 1){
            // player1 turn
            printf("\nIt is player1's turn!, place your piece\n");
            do{
                do{
                    printf("Choose an x coordinate(0 based, inverse directions, x up-down)");
                }while(scanf("%d",&x) == 0);
                do{
                    printf("Choose an y coordinate(0 based, inverse direction, y left-right");
                }while(scanf("%d",&y) == 0);
            }while(placePiece(x,y,0,iBoard,iBoard->player1->piece) == 0);
            placePiece(x,y,1,iBoard,iBoard->player1->piece);
            for(int i = 1; i <= 8; i++){
                char *direction = i == 1? "North": i == 2? "North-East": i == 3? "East": i == 4? "South-East": i == 5? "South": i == 6? "South-West": i == 7? "West": "North-West";
                count = evalBoard(iBoard,x,y,i,1);
                if(count >= 4){
                    printf("\nPlayer1 wins!");
                    return 1;
                }
                else{
                    printf("\nYour placement has %d points in the %s direction\n",count,direction);
                }
            }
            playerTurn = 2;
        }
        else if(playerTurn == 2){
            // player2 turn
            printf("\nIt is player2's turn!, place your piece\n");
            do{
                do{
                    printf("\nChoose an x coordinate(0 based, inverse directions, x up-down)");
                }while(scanf("%d",&x) == 0);
                do{
                    printf("\nChoose an y coordinate(0 based, inverse directions, y left-right)");
                }while(scanf("%d",&y) == 0);
               //debug printf("\nBefore last while condition\n"); 
            }while(placePiece(x,y,0,iBoard,iBoard->player2->piece) == 0);
            // debug printf("\nAfter last while condition\n");
            placePiece(x,y,1,iBoard,iBoard->player2->piece);
            for(int i = 1; i <= 8; i++){
                char *direction = i == 1? "North": i == 2? "North-East": i == 3? "East": i == 4? "South-East": i == 5? "South": i == 6? "South-West": i == 7? "West": "North-West";
                count = evalBoard(iBoard,x,y,i,1);
                if(count >= 4){
                    printf("\nPlayer2 wins!");
                    return 1;
                }
                else{
                    printf("\nYour placement has %d points in the %s direction\n",count,direction);
                }
            }
            playerTurn =1 ;
        }
        //break; debugging purposes

    }

}

