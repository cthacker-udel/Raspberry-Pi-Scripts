#include "project.h"

int main(int argc, char *argv[]){
	if(argc > 1){
		seedRandomNumber(atol(argv[1]));
	}
	else{
		seedRandomNumber(rand());
		seedRandomNumber(rand());
	}
}
