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

void displayHand(pokerCard *hand){
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        fprintf(stderr,"\n%s of %s\n",tempHand->name,tempHand->suit);
        tempHand = tempHand->next;
    }
}

pokerCard * getDeck(void){
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

