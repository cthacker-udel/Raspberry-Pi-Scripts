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
    long int atolNum = atol(argv[1]);
    for(int i = 0; i < atolNum; i++){
        deck = shuffle(deck);
    }
    startGame();
    while(1){
        checkJoystick();
        printf("\n\nNUM OF CARDS : %d\n\n",countCards(deck));
        displayHand(getCombinedHand());
        displaySuits(getCombinedHand());
        int result = evalHand(getCombinedHand());
        switch(result){
            case 1:
                fprintf(stderr,"\nROYAL FLUSH\n");
                break;
            case 2:
                fprintf(stderr,"\nSTRAIGHT FLUSH\n");
                break;
            case 3:
                fprintf(stderr,"\nFOUR OF A KIND\n");
                break;
            case 4:
                fprintf(stderr,"\nFULL HOUSE\n");
                break;
            case 5:
                fprintf(stderr,"\nFLUSH\n");
                break;
            case 6:
                fprintf(stderr,"\nSTRAIGHT\n");
                break;
            case 7:
                fprintf(stderr,"\nTHREE PAIR\n");
                break;
            case 8:
                fprintf(stderr,"\nTWO PAIR\n");
                break;
            case 9:
                fprintf(stderr,"\nPAIR\n");
                break;
            default:
                fprintf(stderr,"\nHIGH CARD\n");
                break;
        }
    }
}
