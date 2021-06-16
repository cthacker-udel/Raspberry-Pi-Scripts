#include "project.h"

void seedRandomNumber(int number){
	srand(number);
}

int generateRandomNumber(){
	return rand();
}

int isNumberStrong(int number){
	int sum = 0;
	int tempNum = number;
	while(number > 10){
		sum += factorial(number % 10);
		number = number / 10;
	}
	sum += number;
	if(sum == tempNum){
		return 1;
	}
	else{
		return 0;
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
