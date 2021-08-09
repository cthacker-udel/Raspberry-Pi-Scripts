#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct thePlayer{

    char *name;
    char piece;


}player;

player *createPlayer();

void placePiecePlayer(player *);
