#include "board.h"

board *makeBoard(){

    int size;
    char piece;

    board *theboard = malloc(sizeof(board));

    printf("\nEnter the board size: lowest is 4");
    scanf("%d",&size);

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

player *getPlayer1(board *theboard){

    return theboard->player1;

}

player *getPlayer2(board *theboard){

    return theboard->player2;

}

