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

pokerCard *createCard(char *,int,char *);

pokerCard *constructDeck(void);

void displayHand(pokerCard *);

int countCards(pokerCard *);

pokerCard *shuffle(pokerCard *);

void displayHandNoNewLine(pokerCard *);

pokerCard *getInitialDeck();

pokerCard *getDeck();

pokerCard *draw(pokerCard *);

pokerCard *initialPlayerHand();

pokerCard *initialComputerHand();

pokerCard *initialTableCards();

pokerCard *getPlayerHand();

pokerCard *addToHand(pokerCard *);

pokerCard *getComputerHand();

pokerCard *getTableCards();

void startGame();

/*
 *
 * pokercombos prototypes
 *
 */

int min(int,int);

int max(int,int);

int royalFlush(pokerCard *);

int getHighCard(pokerCard *);

int straightFlush(pokerCard *);

int fourOfAKind(pokerCard *);

int fullHouse(pokerCard *);

int getLowCard(pokerCard *);

int allSameSuit(pokerCard *);

int allAlternating(pokerCard *);

int isFlush(pokerCard *);

int isStraight(pokerCard *);

int isThreePair(pokerCard *);

int isTwoPair(pokerCard *);

int isPair(pokerCard *);

int evalHand(pokerCard *);
