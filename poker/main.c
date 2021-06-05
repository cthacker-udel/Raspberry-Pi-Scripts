#include "project.h"



int main(void){
    openDisplay();
    openJoystick();
    pokerCard *deck = constructDeck();
    while(1){
        checkJoystick();
        displayHand(deck);
        printf("\n\nNUM OF CARDS : %d\n\n",countCards(deck));
    }
}
