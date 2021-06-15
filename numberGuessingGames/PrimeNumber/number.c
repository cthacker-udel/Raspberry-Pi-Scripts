#include "project.h"

int getRandomNumber(){
	return rand();
}

void getPlayerGuess(){
	printf("\nPLAYER : GUESS IF THE NUMBER IS PRIME(y/n)?\n");
}

void printComputerGuess(){
	printf("\nCOMPUTER GUESSED NUMBER\n");
}

void seedRandomNumber(int theNumber){
	srand(theNumber);
}

