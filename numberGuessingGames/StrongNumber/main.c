#include "project.h"

int main(int argc, char *argv[]){
	if(argc > 1){
		int number = atol(argv[1]);
		seedRandomNumber(number);
	}
	else{
		seedRandomNumber(7);
	}
	while(1){
		int number = generateRandomNumber();
		printf("\nCOMPUTER GENERATED NUMBER\n");
		int answer = getUserInput();
		if(answer == 99){
			break;
		}
		else if(isStrongNumber(number) & answer == 1){
			correctGuess();
		}
		else if(isStrongNumber(number) && answer == 0){
			incorrectGuess();
		}
		else if(!isStrongNumber(number) && answer == 0){
			correctGuess();
		}
		else if(!isStrongNumber(number) && answer == 1){
			inCorrectGuess();
		}		
	}
	displayScore();
}
