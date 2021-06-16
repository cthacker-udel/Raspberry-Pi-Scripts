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
		
	}
}
