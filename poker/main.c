#include "project.h"

pokerCard *deck = NULL;

pokerCard *getDeck(){
    return deck;
}


int main(int argc, char *argv[]){
    openDisplay();
    openJoystick();
    deck = constructDeck();
    if(argc > 1){
        srand48(atol(argv[1]));
    }
    else{
        srand48(rand());
        srand48(rand());
    }
    deck = shuffle(deck);
    startGame();
    while(1){
        checkJoystick();
        printf("\n\nNUM OF CARDS : %d\n\n",countCards(deck));
        displayHandNoNewLine(deck);
    }
}
