#include "project.h"

#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0x1F
#define RED 0xF800
#define YELLOW 0xFFE0
#define ORANGE 0xFBE0
#define BROWN 0x79E0
#define GREEN 0x7E0
#define CYAN 0x7FF


pi_framebuffer_t *fb = NULL;

pokerCard *HEAD = NULL;

pokerCard *playerHand = NULL;

pokerCard *computerHand = NULL;

pokerCard *tableCards = NULL;

pokerCard *combinedHand = NULL;

pokerCard *combinedHand2 = NULL;

pokerCard *addToHand(pokerCard *hand){

    if(hand == NULL){
        hand = draw(getDeck());
        return hand;
    }
    else{
        pokerCard *newCard = draw(getDeck());
        newCard->next = hand;
        hand = newCard;
        return hand;
    }

}


pokerCard *initialComputerHand(){
    pokerCard *computerHand = NULL;
    computerHand = addToHand(computerHand);
    computerHand = addToHand(computerHand);
    return computerHand;
}


pokerCard *initialPlayerHand(pokerCard *deck){
    pokerCard *playerHand = NULL;
    playerHand = addToHand(playerHand);
    playerHand = addToHand(playerHand);
    return playerHand;
}

pokerCard *initialTableCards(pokerCard *deck){
    pokerCard *tableCards = NULL;
    tableCards = addToHand(tableCards);
    tableCards = addToHand(tableCards);
    return tableCards;
}


pokerCard *draw(pokerCard *deck){
    if(deck == NULL){
        fprintf(stderr,"\n!!!!!!! NO CARDS TO DRAW - DECK EMPTY !!!!!!!\n");
        return NULL;
    }
    else{
        pokerCard *topCard = deck;
        pokerCard *prevCard;
        while(topCard->next != NULL){
            prevCard = topCard;
            topCard = topCard->next;
        }
        prevCard->next = NULL;
        return topCard;
    }
}

pokerCard *getPlayerHand(){
    return playerHand;
}

pokerCard *getComputerHand(){
    return computerHand;
}

pokerCard *getTableCards(){
    return tableCards;
}

pokerCard *getCombinedHand(){
    return combinedHand;
}

void freePile(pokerCard *pile){
    pokerCard *tmp;
    while(pile != NULL){
        tmp = pile;
        pile = pile->next;
        free(tmp);
    }
}


pokerCard *combineTwoHands(pokerCard *hand1, pokerCard *hand2){
    int numCardsHand1 = countCards(hand1);
    int numCardsHand2 = countCards(hand2);

    pokerCard *newHand = NULL;
    
    pokerCard *tempCard = hand1;
    while(tempCard != NULL){
        if(!newHand){
            newHand = createCard(tempCard->suit,tempCard->rank,tempCard->name);
            tempCard = tempCard->next;
        }
        else{
            pokerCard *newCard = createCard(tempCard->suit,tempCard->rank,tempCard->name);
            newCard->next = newHand;
            newHand = newCard;
            tempCard = tempCard->next;
        }
    }
    tempCard = hand2;
    while(tempCard != NULL){
        pokerCard *newCard = createCard(tempCard->suit,tempCard->rank,tempCard->name);
        newCard->next = newHand;
        newHand = newCard;
        tempCard = tempCard->next;
    }
    return newHand;
}


void startGame(pokerCard *deck){

    playerHand = initialPlayerHand(deck);
    computerHand = initialComputerHand(deck);
    tableCards = initialTableCards(deck);
    combinedHand = combineTwoHands(playerHand,tableCards);
    combinedHand2 = combineTwoHands(computerHand,tableCards);
    while(countCards(tableCards) < 7){
        fprintf(stderr,"\n\nUSER CURRENT HAND + TABLE CARDS : ");
        displayHand(combinedHand);
        char response;
        do{
            fprintf(stderr,"\nFOLD or Call?(f/c)");
        }while(scanf(" %c",&response) != 1);
        if(response == 'f'){
            freePile(playerHand);
            break;
        }
        else if(countCards(combinedHand) == 7){
            break;
        }
        else if(response == 'c'){
            tableCards = addToHand(tableCards);
            combinedHand = combineTwoHands(playerHand,tableCards);
            combinedHand2 = combineTwoHands(computerHand,tableCards);
        }
        else{
            fprintf(stderr,"\nInvalid input\n");
        }
    }
    if(playerHand != NULL){
        int showdownResult = showDown(combinedHand,combinedHand2);
        switch(showdownResult){
            case 1:
                fprintf(stderr,"\nYOU WIN!\n");
                break;
            case 2:
                fprintf(stderr,"\nYOU LOST!\nOPPONENTS HAND : ");
                displayHand(combinedHand2);
                break;
            case 3:
                fprintf(stderr,"\nIT WAS A TIE, AND YOUR HIGH CARD WON!\nOPPONENTS HAND :");
                displayHand(combinedHand2);
                break;
            case 4:
                fprintf(stderr,"\nIT WAS A TIE, AND YOUR HIGH CARD LOST!\nOPPONENTS HAND :");
                displayHand(combinedHand2);
                break;
            default:
                fprintf(stderr,"\nRUNNING DEFAULT CASE\n");
                break;
        }
    }
    else{
        // throw signal
        raise(SIGABRT); 
    }

}

int compareHighCards(pokerCard *hand1, pokerCard *hand2){
    int numCards1 = countCards(hand1);
    int numCards2 = countCards(hand2);
    int hand1Arr[numCards1];
    int hand2Arr[numCards2];
    pokerCard *tempHead1 = hand1;
    pokerCard *tempHead2 = hand2;
    int hand1Index = 0;
    int hand2Index = 0;
    while(tempHead1 != NULL){
        hand1Arr[hand1Index] = tempHead1->rank;
        tempHead1 = tempHead1->next;
        hand1Index++;
    }
    while(tempHead2 != NULL){
        hand2Arr[hand2Index] = tempHead2->rank;
        tempHead2 = tempHead2->next;
        hand2Index++;
    }
    // cocktail sort both arrays
    int loopVar = 1;
    while(1){
    
        for(int i = 0, j = numCards1-1; i < numCards1-1 && j >= 1; i++,j--){
            int currI = hand1Arr[i];
            int forwardI = hand1Arr[i+1];
            int currJ = hand1Arr[j];
            int prevJ = hand1Arr[j-1];
            if(currI > forwardI){
                hand1Arr[i] = forwardI;
                hand1Arr[i+1] = currI;
                loopVar = 0;
                break;
            }
            else if(currJ < prevJ){
                hand1Arr[j] = prevJ;
                hand1Arr[j-1] = currJ;
                loopVar = 0;
                break;
            }
            loopVar = 1;
        }
        if(loopVar){
            break;
        }
    }
    while(1){
    
        for(int i = 0, j = numCards2-1; i < numCards2-1 && j >= 1; i++, j--){
            int currI = hand2Arr[i];
            int forwardI = hand2Arr[i+1];
            int currJ = hand2Arr[j];
            int prevJ = hand2Arr[j-1];
            if(currI > forwardI){
                hand2Arr[i] = forwardI;
                hand2Arr[i+1] = currI;
                loopVar = 0;
                break;
            }
            else if(currJ < prevJ){
                hand2Arr[j] = prevJ;
                hand2Arr[j-1] = currJ;
                loopVar = 0;
                break;
            }
            loopVar = 1;
        }
        if(loopVar){
            break;
        }

    }

    for(int i = numCards1-1, j = numCards2-1; i >= 0 && j >= 0; i--,j--){
        int currI = hand1Arr[i];
        int currJ = hand2Arr[j];
        if(currI > currJ){
            return 3; // players high card is higher
        }
        else if(currJ > currI){
            return 4; // computers high card is higher
        }
    }
    return 0;

}


int showDown(pokerCard *hand1, pokerCard *hand2){
    if(royalFlush(hand1) && !royalFlush(hand2)){
        return 1;
    }
    else if(!royalFlush(hand1) && royalFlush(hand2)){
        return 2;
    }
    else if(royalFlush(hand1) && royalFlush(hand2)){
        return compareHighCards(hand1,hand2);
    }
    else{
        if(straightFlush(hand1) && !straightFlush(hand2)){
            return 1;
        }
        else if(!straightFlush(hand1) && straightFlush(hand2)){
            return 2;
        }
        else if(straightFlush(hand1) && straightFlush(hand2)){
            return compareHighCards(hand1,hand2);
        }
        else{
            if(fourOfAKind(hand1) && !fourOfAKind(hand2)){
                return 1;
            }
            else if(!fourOfAKind(hand1) && fourOfAKind(hand2)){
                return 2;
            }
            else if(fourOfAKind(hand1) && fourOfAKind(hand2)){
                return compareHighCards(hand1,hand2);
            }
            else{
                if(fullHouse(hand1) && !fullHouse(hand2)){
                    return 1;
                }
                else if(!fullHouse(hand1) && fullHouse(hand2)){
                    return 2;
                }
                else if(fullHouse(hand1) && fullHouse(hand2)){
                    return compareHighCards(hand1,hand2);
                }
                else{
                    if(isFlush(hand1) && !isFlush(hand2)){
                        return 1;
                    }
                    else if(!isFlush(hand1) && isFlush(hand2)){
                        return 2;
                    }
                    else if(isFlush(hand1) && isFlush(hand2)){
                        return compareHighCards(hand1,hand2);
                    }
                    else{
                        if(isStraight(hand1) && !isStraight(hand2)){
                            return 1;
                        }
                        else if(!isStraight(hand1) && isStraight(hand2)){
                            return 2;
                        }
                        else if(isStraight(hand1) && isStraight(hand2)){
                            return compareHighCards(hand1,hand2);
                        }
                        else{
                            if(isThreePair(hand1) && !isThreePair(hand2)){
                                return 1;
                            }
                            else if(!isThreePair(hand1) && isThreePair(hand2)){
                                return 2;
                            }
                            else if(isThreePair(hand1) && isThreePair(hand2)){
                                return compareHighCards(hand1,hand2);
                            }
                            else{
                                if(isTwoPair(hand1) && !isTwoPair(hand2)){
                                    return 1;
                                }
                                else if(!isTwoPair(hand1) && isTwoPair(hand2)){
                                    return 2;
                                }
                                else if(isTwoPair(hand1) && isTwoPair(hand2)){
                                    return compareHighCards(hand1,hand2);
                                }
                                else{
                                    if(isPair(hand1) && !isPair(hand2)){
                                        return 1;
                                    }
                                    else if(!isPair(hand1) && isPair(hand2)){
                                        return 2;
                                    }
                                    else if(isPair(hand1) && isPair(hand2)){
                                        return compareHighCards(hand1,hand2);
                                    }
                                    else{
                                        return compareHighCards(hand1,hand2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



pokerCard *shuffle(pokerCard *deck){
    int numCards = countCards(deck);
    int middle = numCards / 2;

    pokerCard *cut = deck;

    for(int i = 0; i < middle; i++){
        cut = cut->next;
    }

    pokerCard *riffle = cut->next;
    cut->next = 0;
    

    pokerCard *newDeck = 0;
    while(riffle || deck){
        pokerCard *newCard;
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
    HEAD = newDeck;
    return newDeck;

}

pokerCard *combineHands(pokerCard *stack1, pokerCard *stack2){
    pokerCard *tempHead = stack1;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    tempHead->next = stack2;
    return tempHead;
}


pokerCard *createCard(char *suit, int rank, char *name){
   
    pokerCard *newCard = (pokerCard *)malloc(sizeof(pokerCard));
    newCard->suit = (char *)malloc(sizeof(char) * (strlen(suit)+1));
    newCard->name = (char *)malloc(sizeof(char) * (strlen(name)+1));
    strcpy(newCard->suit,suit);
    newCard->rank = rank;
    strcpy(newCard->name,name);
    newCard->next = NULL;
    return newCard;

}

void displayHandNoNewLine(pokerCard *hand){
    pokerCard *tempHand = hand;
    fprintf(stderr,"\n-------------------Displaying Cards-------------------\n");
    while(tempHand != NULL){
        fprintf(stderr,"%s of %s,",tempHand->name,tempHand->suit);
        tempHand = tempHand->next;
    }
    fprintf(stderr,"\n------------------------------------------------------\n");
}

void displayHand(pokerCard *hand){
    //fprintf(stderr,"\nentering displayhand\n");
    pokerCard *tempHand = hand;
    fprintf(stderr,"\n-------------------\nDisplaying Cards\n-------------------\n");
    while(tempHand != NULL){
        fprintf(stderr,"\n%s of %s\n",tempHand->name,tempHand->suit);
        tempHand = tempHand->next;
    }
    fprintf(stderr,"\n----------------------------------------------------------\n");
}

pokerCard * getInitialDeck(void){
    return HEAD;
}

int countCards(pokerCard *hand){
    int count = 0;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        count++;
        tempHand = tempHand->next;
    }
    return count;
}


void displaySuits(pokerCard *hand){
    pokerCard *tempHead = hand;
    int count = 0;
    char suits[][10] = {"Hearts","Clubs","Diamonds","Spades"};
    fprintf(stderr,"\nThe suits are :\n");
    for(int i = 0; i < 4; i++){
        char *suit = suits[i];
        while(tempHead != NULL){
            if(strcmp(suit,tempHead->suit) == 0){
                count++;
            }
            tempHead = tempHead->next;
        }
        tempHead = hand;
        fprintf(stderr,"%s : %d\n",suit,count);
        count = 0;
    }
}


pokerCard * constructDeck(void){
    
    char suits[][10] = {"Hearts","Clubs","Diamonds","Spades"};
    char names[][10] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            if(HEAD == NULL){
                HEAD = createCard(suits[i],j,names[j-1]);
            }
            else{
                pokerCard *newHead = createCard(suits[i],j,names[j-1]);
                newHead->next = HEAD;
                HEAD = newHead;
            }
        }
    }
    return HEAD;

}



void openDisplay(void){

    if(!fb){
        fb = getFrameBuffer();
    }
    else{
        fprintf(stderr,"Unable to intialize a framebuffer that has already been initialized");
    }

}


void closeDisplay(void){

   if(fb){
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        fb = NULL;
   }
   else{
        fprintf(stderr,"Attempting to close a framebuffer that has not been initialized or otherwise already closed");
   }

}


void clearDisplay(void){

   if(!fb){
        fprintf(stderr,"Attemping to clear the framebuffer when it has not been initialized");
   }
   else{
        clearFrameBuffer(fb,BLACK);
   }

}

