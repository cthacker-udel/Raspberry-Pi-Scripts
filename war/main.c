#include "project.h"

int main(int argc, char *argv[]){

    if(argc > 1){
        printf("\nEntered first if\n");
        sleep(2);
        int number = atol(argv[1]);
        printf("\nNumber = %d",number);
        srand48(number);
    }
    else{
        srand(7);
    }

    warCard *deck = craftDeck();
    //printHand(deck);
    printf("Before shuffle : %p --- %s of %s",deck,deck->rank,deck->suit);
    printHandNoNewLine(deck);
    //printHandNoNewLine(deck);
    deck = shuffle(deck);
    printf("\nAfter shuffle : %p--- %s of %s",deck,deck->rank,deck->suit);
    printf("\n\n-------------\n\n");
    //printHandNoNewLine(deck);
    //printHand(deck);
    //startGame(deck);
}
