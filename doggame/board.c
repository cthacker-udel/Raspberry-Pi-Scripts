#include "board.h"

board *makeBoard(){

    int size;
    char piece;

    board *theboard = malloc(sizeof(board));

    printf("\nEnter the board size: lowest is 4");
    scanf("%d",&size);
    theboard->theboard = malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){

        *(theboard->theboard+i) = malloc(sizeof(char) * size);

    }
    // initializing the board

    player *player1 = createPlayer();
    player *player2 = createPlayer();

    printf("\nEnter default piece to fill board with");
    scanf(" %c",&piece);

    theboard->defaultPiece = piece;
    theboard->size = size;
    theboard->player1 = player1;
    theboard->player2 = player2;

    return theboard;

}

void makeStartFinish(board *theboard){

    int randomX = rand() % theboard->size; // set y to 0
    int randomY = rand() % theboard->size; // set y to size-1

    *(*(theboard->theboard+randomX)+0) = 'E';
    *(*(theboard->theboard+randomY)+theboard->size-1) = 'F'; 

}

void printBoard(board *theboard){

    for(int i = 0; i < theboard->size; i++){

        for(int j = 0; j < theboard->size; j++){

            printf(" %c ",*(*(theboard->theboard+i)+j));

        }

    }

}

player *getPlayer1(board *theboard){

    return theboard->player1;

}

player *getPlayer2(board *theboard){

    return theboard->player2;

}

int getSize(board *theboard){

    return theboard->size;

}

char getDefPiece(board *theboard){

    return theboard->defaultPiece;

}

void setDefPiece(char thePiece, board *theboard){

    theboard->defaultPiece = thePiece;

}

