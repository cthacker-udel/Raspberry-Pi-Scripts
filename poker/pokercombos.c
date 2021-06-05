#include "project.h"

int royalFlush(pokerCard *hand){
    if(allSameSuit(hand)){
        
    }
}


int allSameSuit(pokerCard *hand){
    char *suit = hand->suit;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        if(strcmp(suit,tempHand->suit) != 0){
            return 0;
        }
        tempHand = tempHand->next;
    }
    return 1;
}

int allAlternating(pokerCard *hand){
    int rank = hand->rank;
    pokerCard *tempHand = hand;
    int numCards = countCards(hand);
    int ranks[numCards];
    int i = 0;
    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        i++;
        tempHand = tempHand->next;
    }
    
    // sort arr
    
    int sortVar = 1;
    while(1){
        for(int i = 0; i < numCards-1; i++){
            int firstNum = ranks[i];
            int secondNum = ranks[i+1];
            if(firstNum > secondNum){
                ranks[i] = secondNum;
                ranks[i+1] = firstNum;
                sortVar = 0;
                break;
            }
            else{
                sortVar = 1;
            }
        }
        if(sortVar){
            break;
        }
    }

    // arr sorted
    

    for(int i = 0; i < numCards-1; i++){
        int firstNum = ranks[i];
        int secondNum = ranks[i+1];
        if(fabs(firstNum - secondNum) <= 1){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;

}
