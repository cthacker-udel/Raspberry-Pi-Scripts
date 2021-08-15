#include "player.h"

int getPlayerStrength(player *thePlayer){

    return thePlayer->strength;

}

player *createPlayer(){

    char *theName = malloc(sizeof(char) * 100);
    printf("\nEnter the name of the player");
    scanf("%s",theName);
    printf("\nEnter the strength of the player\n");
    int theStrength;
    scanf("%d",&theStrength);
    printf("\nEnter the first initial of the player");
    char firstInitial;
    char lastInitial;
    char piece;
    scanf(" %c",&firstInitial);
    printf("\nEnter the last initial of the player");
    scanf(" %c",&lastInitial);
    printf("\nEnter the piece character of the player\n");
    scanf(" %c",&piece);
    player *thePlayer = malloc(sizeof(player));
    thePlayer->firstInitial = firstInitial;
    thePlayer->lastInitial = lastInitial;
    thePlayer->piece = piece;
    thePlayer->name = theName;
    thePlayer->strength = theStrength;
    return thePlayer;

}

char getPlayerFirstInitial(player *thePlayer){

    return thePlayer->firstInitial;

}