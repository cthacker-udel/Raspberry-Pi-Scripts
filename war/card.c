#include "project.h"

warCard *deck = NULL;

warCard *playerHand = NULL;

warCard *computerHand = NULL;


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


warCard *deal(warCard *hand){
	warCard *theCard = hand;
	hand = hand->next;
	return theCard;
}

void addToHand(warCard *hand){
	if(hand){
		warCard *newCard = deal(deck);
		newCard->next = hand;
		hand = newCard;
	}
	else{
		fprintf(stderr,"\nhand passed into the function is NULL\n");
		hand = deal(deck);
	}
}


warCard *initializePlayerHand(){
	if(deck){
		for(int i = 0; i < 26; i++){
			addToHand(playerHand); 
		}
	}
}

warCard *initializeComputerHand(){
	if(deck){
		for(int i = 0; i < 26; i++){
			addToHand(computerHand);
		}
	}
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
	tempHead = deck;
	for(;tempHead || riffle;){
		if(riffle && drand48() > 0.5){
			if(!newDeck){
				warCard *newCard = deal(riffle);
				newCard->next = newDeck;
			}
			else{
				warCard *newCard = deal(riffle);
				newDeck = newCard;
			}
		}
		else if(tempHead){
			if(!newDeck){
				warCard *newCard = deal(tempHead);
				newCard->next = newDeck;
			}
			else{
				warCard *newCard = deal(tempHead);
				newDeck = newCard;
			}
		}
	}
	return newDeck;

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

void printHand(warCard *hand){
    int count = 1;
    warCard *tempHand = hand;
    while(tempHand != NULL){
        printf("\nCARD %d : %s of %s, rank : %d",count++,tempHand->rank,tempHand->suit,tempHand->val);
        tempHand = tempHand->next;
    }
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
	initializePlayerHand();
	initializeComputerHand();
	int playerWins = 0;
	int computerWins = 0;
	while(playerHand || computerHand){
		fprintf(stderr,"\nEach player DRAW!!\n");
		warCard *playerCard = deal(playerHand);
		warCard *computerCard = deal(computerHand);
		int showdownResult = showdown(playerCard,computerCard);
		if(showdownResult == 1){
			playerWins++;
		}
		else if(showdownResult == 2){
			computerWins++;
		}
		else{
			fprintf(stderr,"\nEnded in a draw, no points awarded to either team\n");
		}
	}
}


