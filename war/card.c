#include "project.h"

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
    if(hand == NULL){
        return NULL;
    }
	warCard *theCard = hand;
    warCard *prevCard;
    while(theCard->next != NULL){
        prevCard = theCard;
        theCard = theCard->next;
    }
    prevCard->next = NULL;
	return theCard;
}

warCard * addToHand(warCard *hand, warCard *iDeck){
	if(hand){
		warCard *newCard = deal(iDeck);
		newCard->next = hand;
		hand = newCard;
        return hand;
	}
	else{
		fprintf(stderr,"\nhand passed into the function is NULL\n");
		hand = deal(iDeck);
        return hand;
	}
}


void initializePlayerHand(warCard *iDeck){
    warCard *newCard;
	if(iDeck){
		for(int i = 0; i < 26; i++){
            newCard = iDeck;
            iDeck = iDeck->next;
            newCard->next = playerHand;
            playerHand = newCard;
		}
	}
}

void initializeComputerHand(warCard *iDeck){
	warCard *newCard;
    if(iDeck){
		for(int i = 0; i < 26; i++){
            newCard = iDeck;
            iDeck = iDeck->next;
            newCard->next = computerHand;
            computerHand = newCard;
		}
	}
}

void printNumberOfCards(warCard *hand){
    int count = 0;
    warCard *tempHand = hand;
    while(tempHand != NULL){
        count++;
        tempHand = tempHand->next;
    }
    printf("\nThe number of cards is : %d\n",count);
}

int numberOfCards(warCard *hand){
    int count = 0;
    warCard *tempHead = hand;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;
}

void listNodes(warCard *list){
    int count = 0;
    while(list != NULL){
        printf("\n-----\nNODE %d : %d\n-----",count++,list->val);
        list = list->next;
    }
}





warCard *shuffle(warCard *deck){

	int middle = countCards(deck) / 2;
    
    warCard *cut = deck;

    for(int i = 0; i < middle; i++){
        cut = cut->next;
    }

    warCard *riffle = cut->next;
    cut->next = 0;

    warCard *newDeck = 0;
        
    while(riffle || deck){
        warCard *newCard;
        if(riffle != NULL && drand48() < .5){
            newCard = riffle;
            riffle = riffle->next;
            newCard->next = newDeck;
            newDeck = newCard;
        }
        else if(deck){
            newCard = deck;
            deck = deck->next;
            newCard->next = newDeck;
            newDeck = newCard;
        }
    }
    printf("Number of cards in riffle : %d and Number of cards in deck = %d\n",numberOfCards(riffle),numberOfCards(deck));
    return newDeck;
}




warCard *craftDeck(){
    warCard *iDeck = NULL;
    char suits[][10] = {"Hearts","Clubs","Diamonds","Spades"};
    char ranks[][10] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
    for(int j = 0; j < 4; j++){
        for(int i = 1; i <= 13; i++){
            if(iDeck == NULL){
                iDeck = createCard(ranks[i-1],suits[j],i);
            }
            else{
                warCard *newCard = createCard(ranks[i-1],suits[j],i);
                newCard->next = iDeck;
                iDeck = newCard;
            }
        }
    }
    return iDeck;
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

warCard *getPlayerHand(){
    return playerHand;
}

warCard *getComputerHand(){
    return computerHand;
}


void startGame(warCard *iDeck){
	playerHand = initializePlayerHand(iDeck);
	computerHand = initializeComputerHand(iDeck);
	int playerWins = 0;
	int computerWins = 0;
	while(playerHand || computerHand){
		fprintf(stderr,"\nEach player DRAW!!\n");
		warCard *playerCard = deal(playerHand);
		warCard *computerCard = deal(computerHand);
        printHand(playerCard);
        printHand(computerCard);
        sleep(2);
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


