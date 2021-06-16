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
		if(isStrongNumber(number) & answer == 1){
			// correct guess
		}
		else if(isStrongNumber(number) && answer == 0){
			// incorrect guess
		}
		else if(!isStrongNumber(number) && answer == 0){
			// correct guess
		}
		else if(!isStrongNumber(number) && answer == 1){
			// incorrect guess
		}		
	}
}
