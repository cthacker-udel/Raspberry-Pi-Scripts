#include "project.h"
#include "number.c"

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

    char *guess = NULL;

    while(1){

        int theNumber = getComputerGuess();
        getPlayerGuess();
        scanf("%s",guess);
        printf("The guess is : %s",guess);
        printf("The computer guess is : %d",theNumber);
        

    }

    return 0;


}