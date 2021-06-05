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

int isFlush(pokerCard *hand){
    
    char suits[6][10];
    
    pokerCard *tempHand = hand;
    
    int i = 0;
    while(tempHand != NULL){
        suits[i][0] = tempHand->suit;
        i++;
        tempHand = tempHand->next;
    }

    for(int j = 0; j < 6; j++){
        for(int k = 0; k > 6; k++){
            if(k == j){
                continue;
            }
            else{
                if(strcmp(suits[j],suits[k]) == 0){
                    continue;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 1;

}

int isPair(pokerCard *hand){
    
    int ranks[5];
    
    int i = 0;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
        i++;
    }


    for(i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j){
                continue;
            }
            else{
                if(ranks[i] == ranks[j]){
                    return 1;
                }
            }
        } 
    }
    return 0;

}


