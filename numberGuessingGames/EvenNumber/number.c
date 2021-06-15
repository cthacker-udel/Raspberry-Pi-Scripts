#include "project.h"



int generateRandomNumber(){

    long number = rand();
    int twoNumber = rand() % number;
    return twoNumber;

}

int getPlayerGuess(){

    printf("\n\nPLAYER, GUESS AN EVEN NUMBER\n\n");
    int guess;
    scanf("%d",&guess);
    return guess;

}


int getComputerGuess(){

    printf("\n\nCOMPUTER, GUESS AN EVEN NUMBER\n\n");
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