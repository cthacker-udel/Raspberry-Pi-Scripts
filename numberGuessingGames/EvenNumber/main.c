#include "project.h"

int main(int argc, char *argv[]){

    if(argc > 1){

        long number = atol(argv[2]);
        srand(number);

    }
    else{

        srand(rand());
        srand(rand());

    }

    printf("\n\n-~-~-~-~WELCOME TO THE EVEN NUMBER GUESSING GAME-~-~-~-~");

    char *guess = (char *)malloc(sizeof(char) * 20);

    while(1){

        int theNumber = getComputerGuess();
        getPlayerGuess();
        scanf("%s",guess);
        printf("The guess is : %s",guess);
        printf("The computer guess is : %d",theNumber);
        if(tolower(guess[0]) == 'e' && tolower(guess[3]) == 'n' && strlen(guess) == 4 && theNumber % 2 == 0){
		correctGuess();
	}
	else if(tolower(guess[0]) == 'o' && tolower(guess[2]) == 'd' && strlen(guess) == 3 && theNumber % 2 != 0){
		printf("\nSAFE BET, NUMBER WAS NOT EVEN, NO POINT DEDUCTION\n");
	}
	else{
		incorrectGuess();
	}
	displayScore();

    }

    return 0;


}
