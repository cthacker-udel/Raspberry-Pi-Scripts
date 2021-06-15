#include "project.h"

int playerScore = 0;
int computerScore = 0;

int generateRandomNumber(){

    long number = rand();
    int twoNumber = rand() % number;
    return twoNumber;

}

void displayScore(){

    printf("\n!#!#!#!#SCORE DISPLAY!#!#!#!#\n\nPLAYER SCORE : %d\n\nCOMPUTER SCORE : %d\n\n!#!#!#!#!#!#!#!#\n",playerScore,computerScore);

}

void correctGuess(){

    printf("\n\nTHE GUESS IS\n\n....");
    printf("CORRECT!\n");
    playerScore++;

}

void incorrectGuess(){

    printf("\n\nTHE GUESS IS\n\n....");
    printf("INCORRECT!\n");
    computerScore++;

}

void getPlayerGuess(){

    printf("\n\nPLAYER, GUESS AN EVEN NUMBER\n\n");

}


int getComputerGuess(){

    int guess;
    while(1){
        int theNumber = generateRandomNumber();
        if(theNumber % 2 == 0){
            guess = theNumber;
            break;
        }
    }
    return guess;

}
