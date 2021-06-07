#include "project.h"



pokerCard *initalPlayerHand(pokerCard *deck){
    
}



int main(void){
    openDisplay();
    openJoystick();
    pokerCard *deck = constructDeck();
    srand(rand());
    deck = shuffle(deck);
    while(1){
        checkJoystick();
        printf("\n\nNUM OF CARDS : %d\n\n",countCards(deck));
    }
}
