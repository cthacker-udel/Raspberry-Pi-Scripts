
int main(int argc, char *argv[]){
	if(argc > 1){
		seedRandomNumber(atol(argv[2]));
	}
	else{
		seedRandomNumber(rand());
		seedRandomNumber(rand());
	}
}
