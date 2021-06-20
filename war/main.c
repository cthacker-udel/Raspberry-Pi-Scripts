#include "project.h"



int main(int argc, char *argv[]){
    
    warCard *deck = craftDeck();
    if(argc > 1){
        printf("\nEntered first if\n");
        sleep(2);
        int number = atol(argv[1]);
        printf("\nNumber = %d",number);
        srand48(number);
        for(int i = 0; i < number; i++){
            deck = shuffle(deck);
        }
    }
    else{
        srand(7);
    }
    int times;
    if(drand48() < 0.5){
        times = rand() % 51;
    }
    else{
        times = rand() % 101;
    }
    for(int i = 0; i < times; i++){
        deck = shuffle(deck);
    }
}
