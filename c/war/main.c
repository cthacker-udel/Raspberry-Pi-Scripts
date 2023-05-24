#include "project.h"

warCard *deck = NULL;

int main(int argc, char *argv[]){
    
    deck = craftDeck();
    if(argc > 1){
        int number = atol(argv[1]);
        printf("\nNumber = %d",number);
        srand48(number);
        for(int i = 0; i < number; i++){
            deck = shuffle(deck);
        }
    }
    else{
        srand((unsigned)time(NULL));
        srand48((unsigned)time(NULL));
    }
    printHandNoNewLine(deck);
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
    startGame(deck);
}
