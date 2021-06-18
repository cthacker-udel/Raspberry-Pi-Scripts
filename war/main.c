#include "project.h"

int main(int argc, char *argv[]){

    if(argc > 1){
        int number = atol(argv[1]);
        srand(number);
    }
    else{
        srand(7);
    }

    warCard *deck = craftDeck();
    printNumberOfCards(deck);
    deck = shuffle(deck);
    printNumberOfCards(deck);
}
