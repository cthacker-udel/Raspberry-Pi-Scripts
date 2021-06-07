#include "project.h"

pokerCard *deck = NULL;

pokerCard *getDeck(){
    return deck;
}


int main(void){
    openDisplay();
    openJoystick();
    pokerCard *deck = constructDeck();
    srand(rand());
    deck = shuffle(deck);
    pokerCard *newCard = draw(deck);
    while(1){
        checkJoystick();
        printf("\n\nNUM OF CARDS : %d\n\n",countCards(deck));
        displayHandNoNewLine(deck);
        displayHandNoNewLine(newCard);
        newCard = draw(deck);
    }
}
