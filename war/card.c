#include "project.h"

warCard *deck = NULL;


warCard *createCard(char *rank, char *suit, int val){
    warCard *newCard = (warCard *)malloc(sizeof(warCard));
    strcpy(newCard->rank,rank);
    strcpy(newCard->suit,suit);
    newCard->val = val;
    newCard->next = NULL;
    return newCard;
}



int countCards(warCard *hand){
	int count = 0;
	warCard *tempHead = hand;
	while(tempHead != NULL){
		count++;
		tempHead = tempHead->next;
	}
	return count;
}


warCard *shuffle(warCard *deck){

	int middle = countCards(deck) / 2;
	warCard *tempHead = deck;
	int count = 0;
	while(count != middle){
		tempHead = tempHead->next;
		count++;
	}
	warCard *riffle = tempHead->next;
	tempHead->next = NULL;
	warCard *newDeck;
	for(;tempHead || riffle;){
		if(riffle && srand() > 0.5){
		
		}
	}

}




warCard *craftDeck(){
    char suits[][10] = {"Hearts","Clubs","Diamonds","Spades"};
    char ranks[][10] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
    for(int j = 0; j < 4; j++){
        for(int i = 1; i <= 13; i++){
            if(deck == NULL){
                deck = createCard(ranks[i-1],suits[j],i);
            }
            else{
                warCard *newCard = createCard(ranks[i-1],suits[j],i);
                newCard->next = deck;
                deck = newCard;
            }
        }
    }
    return deck;
}

char *getSuit(warCard *card){

	return card->suit;

}


char *getRank(warCard *card){

	return card->rank;
}


int getValue(warCard *card){

	return card->val;

}


int showdown(warCard *playerCard, warCard *computerCard){
	return playerCard->val > computerCard->val? 1: playerCard->val < computerCard->val? 2: 3;
}


void startGame(){

}


