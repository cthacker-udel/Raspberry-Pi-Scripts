#include "project.h"

void seedRandomNumber(int number){
	srand(number);
}

int generateRandomNumber(){
	return rand();
}

int isNumberStrong(int number){
	int sum = 0;
	while(number > 10){

	}
}

int factorial(int number){
	if(number < 10){
		return number;
	}
	else{
		return number % 10 * factorial(number / 10);
	}
}
