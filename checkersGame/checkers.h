#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <signal.h>
#include "sense.h"
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef struct piece{

    int xCoord;
    int yCoord;
    int isKing;
    struct piece *next;

}checkersPiece;


checkersPiece *makePiece(int x, int y, int isKing);

void display_team_1(pi_framebuffer_t *dev);

void display_team_2(pi_framebuffer_t *dev);

void openDisplay(void);

void closeDisplay(void);

void openJoystick(void);

void closeJoystick(void);

void checkJoystick(void);


void display_user_team(void);

void display_computer_team(void);
