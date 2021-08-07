#include "player.h"


player *createPlayer(){

    char *newName = (char *)malloc(sizeof(char) * 100);
    printf("Enter the player's name");
    scanf("%s",newName);

    printf("Enter the player's piece");
    char piece;
    scanf(" %c",&piece);

    player *newPlayer = (player *)malloc(sizeof(player));
    newPlayer->name = (char *)malloc(sizeof(char) * strlen(newName));
    strcpy(newPlayer->name,newName);
    newPlayer->piece = piece;
    return newPlayer;

}

void placePiece(player *thePlayer){

    printf("%s places their piece!",thePlayer->name);

}
