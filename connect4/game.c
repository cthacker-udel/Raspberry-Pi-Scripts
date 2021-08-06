#include "board.h"
#include "player.h"

int main(void){

    int theSize;
    printf("\nEnter the size of the board, board will be NxN dimensions : ");
    scanf("%d",&theSize);
    board *iBoard = newBoard(theSize,theSize);
    // board constructed

    // create players
    iBoard->player1 = createPlayer();
    iBoard->player2 = createPlayer();

    while(1){
        // game loop




    }

}

