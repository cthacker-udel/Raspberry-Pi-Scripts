#include <stdio.h>
#include <stdlib.h> // for drand48
#include "card.h"

/* counts the number of cards in the list headed by "deck" */
int countPile(cardT *pile) {
    int count=0;
    /* When "deck" is NULL (zero), it's at the end. Otherwise,
     * move to the next card and increment the count.
     */
    for(count=0; pile; pile=pile->next)
    {
        count++;
    }
    return count;
}

cardT *makeCard(int rank, char suit){
    if(suit != 'C' && suit != 'D' && suit != 'H' && suit != 'S'){
        return NULL;
    }
    if(rank < 1 || rank > 13){
        return NULL;
    }
    cardT *x = malloc(sizeof(cardT));
    x->rank = rank;
    x->suit = suit;
    x->next = NULL;
    return x;
}

cardT *makeDeck(void){
    cardT *deck = NULL;
    cardT *head = NULL;
    char suits[5] = {'C','D','H','S'};
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            if(head == NULL){
                deck = makeCard(j,suits[i]);
                head = deck;
            }
            else{
                deck = head;
                cardT *newCard = makeCard(j,suits[i]);
                while(deck->next != NULL){
                    deck = deck->next;
                }
                deck->next = newCard;
            }
        }
    }
    return head;
}

void showPile(cardT *pile){
    cardT *head = pile;
    while(head != NULL){
        printf("%d%c ",head->rank,head->suit);
        head = head->next;
    }

}


void freePile(cardT *pile){

    cardT *tmp;
    while(pile != NULL){
        tmp = pile;
        pile = pile->next;
        free(tmp);
    }

}

int totalPile(cardT *pile){
    int theTotal = 0;
    cardT *head = pile;
    while(head != NULL){
        if(head->rank > 10){
            theTotal += 10;
        }
        else{
            theTotal += head->rank;
        }
        head = head->next;
    }
    return theTotal;

}

cardT *deal(cardT *pile){

    if(pile == NULL){
        return NULL;
    }
    cardT *head = pile;
    cardT *prevNode;
    while(head->next != NULL){
        prevNode = head;
        head = head->next;
    }
    prevNode->next = NULL;
    return head;

}

/* Emulates a "riffle shuffle" of "deck". */
cardT *shuffle(cardT *deck) {
    int size = countPile(deck);
    cardT *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    cardT *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    cardT *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        cardT *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}
