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


void setTurn(int);

int validMove(checkersPiece *, int, int);

checkersPiece *makePiece(int x, int y, int isKing);

void display_created_user_team(void);

void removeComputerPiece(int,int);

void removePlayerPiece(int,int);

void display_created_computer_team(void);

void display_team_1(pi_framebuffer_t *dev);

void display_team_2(pi_framebuffer_t *dev);

void openDisplay(void);

void closeDisplay(void);

void openJoystick(void);

void closeJoystick(void);

void checkJoystick(void);

checkersPiece *craftPiece(int,int);

void showTeam(checkersPiece *);

checkersPiece *getPlayerTeam();

checkersPiece *getComputerTeam();

checkersPiece *getPlayerCURR();

checkersPiece *getComputerCURR();

void coinFlip();

int getTurn();

void setDelay(int);

void currCursor(checkersPiece *);

void display_user_team(void);

void display_computer_team(void);

pi_framebuffer_t *getDisplay();

int getChooseMove();

int getXCoord();

int getYCoord();

void displayChooseMove(int,int,char);

void clearDisplay(void);

int getColorVal(int,int);

