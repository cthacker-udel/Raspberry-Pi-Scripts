#include "node.h"

typedef struct theDLL{

    node *first;
    node *last;
    int numRacers;
    int totWins; // among all racers
    int totLosses; // among all racers
    int totTies; // among all racers

}DLL;

void push(node *);

node *createNode();

node *pop();

int remove(int);

void moveUp(int);

void moveDown(int);

void raceOff(int,int);

