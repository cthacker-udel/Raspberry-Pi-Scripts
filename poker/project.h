#include <signal.h>
#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

typedef struct card{

    char *suit;
    int rank;
    char *name;
    struct card *next;


}pokerCard;


void openJoystick(void);
void closeJoystick(void);
void checkJoystick(void);
void handler(unsigned int);


void openDisplay(void);
void closeDisplay(void);
void clearDisplay(void);

pokerCard *constructDeck(void);

void displayHand(pokerCard *);

int countCards(pokerCard *);

pokerCard *shuffle(pokerCard *);

void displayHandNoNewLine(pokerCard *);

pokerCard *getInitialDeck();

pokerCard *getDeck();

pokerCard *draw(pokerCard *);

pokerCard *addToHand(pokerCard *);

pokerCard *initialPlayerHand(void);

pokerCard *initialComputerHand(void);

pokerCard *initialTableCards(void);

pokerCard *getPlayerHand();

pokerCard *getComputerHand();

pokerCard *getTableCards();

void startGame(void);
