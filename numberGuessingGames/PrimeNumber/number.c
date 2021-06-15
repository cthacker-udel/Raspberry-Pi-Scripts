#include "project.h"

int playerScore = 0;
int computerScore = 0;
int quit_var = 1;

void displayScore(){
	printf("\n~=~=~= CURR SCORE ~=~=~=\nPLAYER : %d\nCOMPUTER : %d\n~=~=~=~=~=~=~=~=~=~=~=~=~=\n",playerScore,computerScore);
}

int getQuitVar(){
	return quit_var;
}

int getPlayerScore(){
	return playerScore;
}

int getComputerScore(){
	return computerScore;
}

int getRandomNumber(){
	return rand();
}

int getPlayerGuess(){
	printf("\nPLAYER : GUESS IF THE NUMBER IS PRIME(y/n)? q to quit\n");
	char *guess = (char *)malloc(sizeof(char) * 4);
	scanf("%s",guess);
	if(tolower(guess[0]) == 'y'){
		return 1;
	}
	else if(tolower(guess[0]) == 'n'){
		return 0;
	}
	else{
		return 2;
	}
}

int isPrime(int number){
	if(number < 0){
		return 0;
	}
	else if(number == 1){
		return number;
	}
	else if(number <= 7 && number == 2 || number == 3 || number == 5 || number == 7){
		return 1;
	} 
	else{
		for(int i = 0; i <= sqrt(number); i++){
			if(number % i == 0){
				return 0;
			}
		}
		return 1;
	}
}

void printComputerGuess(){
	int number = getRandomNumber();
	printf("\nCOMPUTER GUESSED NUMBER : %d\n",number);
	int res = getPlayerGuess()
	if(res == 2){
		quit_var = 0;
	}
	else if(isPrime(number) && res){
		printf("\nYOU ANSWERED CORRECTLY, NUMBER IS PRIME AND YOU ANSWERED YES\n");
		printf("\nYOUR SCORE INCREASES BY 1 WHILE COMPUTER'S DECREASES BY 1\n");
		playerScore++;
		computerScore++;
		displayScore();
	}
	else if(isPrime(number) && !res){
		printf("\nYOU ANSWERED INCORRECTLY, NUMBER IS NOT PRIME AND YOU ANSWERED NO\n");
		printf("\nYOUR SCORE DECREASES BY 1 WHILE COMPUTER'S INCREASES BY 1\n");
		playerScore--;
		computerScore++;
		displayScore();
	}
	else if(!isPrime(number) && res){
		printf("\nYOU ANSWERED INCORRECTLY, NUMBER IS NOT PRIME AND YOU ANSWERED YES\n");
		printf("\nYOUR SCORE DESCREASES BY 1 WHILE COMPUTER'S INCREASES BY 1\n");
		playerScore--;
		computerScore++;
		displayScore();
	}
	else if(!isPrime(number) && !res){
		printf("\nYOU ANSWERED CORRECTLY, NUMBER IS NOT PRIME AND YOU ANSWERED NO\n");
		printf("\nYOUR SCORE INCREASES BY 1 WHILE COMPUTER'S DECREASES BY 1\n");
		playerScore++;
		computerScore--;
		displayScore();
	}
}	

void seedRandomNumber(int theNumber){
	srand(theNumber);
}

