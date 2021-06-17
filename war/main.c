#include "project.h"

int main(int argc, char *argv[]){

    warCard *deck = craftDeck();
    printNumberOfCards(deck);
    warCard *newCard = deal(deck);
    printNumberOfCards(deck);

}
