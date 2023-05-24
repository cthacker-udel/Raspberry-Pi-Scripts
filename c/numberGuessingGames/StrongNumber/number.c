#include "project.h"

int userScore;
int computerScore;

void seedRandomNumber(int number){
	srand(number);
}

void displayScore(){
	printf("\n~-~-~-SCORE~-~-~-\nUSER : %d\nCOMPUTER : %d\n~-~-~-~-~-~-~-~-~-\n",userScore,computerScore);
}

void getWinner(){
	if(userScore > computerScore){
		printf("\n~-~-~-FINAL GAME RESULTS~-~-~-\nWINNER : USER\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	}
	else if(computerScore > userScore){
		printf("\n~-~-~-FINAL GAME RESULTS~-~-~-\nWINNER : COMPUTER\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");	
	}
	else{
		printf("\n~-~-~-FINAL GAME RESULTS~-~-~-\nTIE\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	}	
}

void correctGuess(){
	printf("~-~-~-ANSWER RESULT~-~-~-\n--- CORRECT ---\n~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	userScore++;
	computerScore--;
	displayScore();
}

void incorrectGuess(){
	printf("~-~-~-ANSWER RESULT~-~-~-\n--- INCORRECT ---\n~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
	userScore--;
	computerScore++;
	displayScore();
}

int getUserInput(){
	while(1){
		printf("\nUSER : ENTER 1 IF NUMBER IS STRONG NUMBER OR 0 IF NOT, 99 to quit program\n");
		int answer;
		scanf("%d",&answer);
		if(answer == 99){
			return 99;
		}
		else if(answer != 1 && answer != 0){
			continue;
		}
		else{
			return answer;
		}
	}
}

int generateRandomNumber(){
	return rand();
}

int isStrongNumber(int number){
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
