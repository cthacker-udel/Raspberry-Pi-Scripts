#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct thePlayer{

    char *name;
    int strength;
    char piece;
    char firstInitial;
    char lastInitial;

}player;

int getPlayerStrength(player *);

player *createPlayer();

char getPlayerFirstInitial(player *);

char getPlayerLastInitial(player *);

char getPlayerPiece(player *);