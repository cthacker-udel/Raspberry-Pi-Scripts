/*
 * @author - Cameron Thacker
 *
 */

#include "project.h"

int min(int,int);

int max(int,int);

int royalFlush(pokerCard *hand){
    if(allSameSuit(hand)){
        if(allAlternating){
            if(getLowCard(hand) == 10 && getHighCard(hand) == 13){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }        
    }
    else{
        return 0;
    }
}

int getHighCard(pokerCard *hand){
    int numCards = countCards(hand);
    int ranks[numCards];
    pokerCard *tempHead = hand;
    int i = 0;
    int maxNum = 0;
    while(tempHead != NULL){
        ranks[i] = tempHead->rank;
        i++;
        tempHead = tempHead->next;
    }

    for(int i = 0; i < numCards-1; i++){
        int firstRank = numCards[i];
        int secondRank = numCards[i+1];
        maxNum = max(firstRank,secondRank);
    }
}

int getLowCard(pokerCard *hand){
    int numCards = countCards(hand);
    int ranks[numCards];
    pokerCard *tempHead = hand;
    int index = 0;
    int minNum = 0;
    while(tempHead != NULL){
        ranks[index] = tempHead->rank;
        tempHead = tempHead->next;
        index++;
    }

    for(int i = 0; i < numCards-1; i++){
        int firstRank = numCards[i];
        int secondRank = numCards[i+1];
        minNum = min(firstRank,secondRank);
    }
    return minNum;
}

int max(int x, int y){
    if(x > y){
        return x;
    }
    else if(y > x){
        return y;
    }
    else{
        return x;
    }
}

int min(int x, int y){
    if(x > y){
        return y;
    }
    else if(y > x){
        return x;
    }
    else{
        return y;
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

int isThreePair(pokerCard *hand){
    int ranks[5];

    int i = 0;
    pokerCard *tempHand = hand;

    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
    }

    int count = 0;
    for(i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j){
                continue;
            }
            else if(ranks[i] == ranks[j]){
                count++;
            }
        }
        if(count == 3){
            return 1;
        }
        else{
            count = 0;
        }
    }
    return 0;

}

int isTwoPair(pokerCard *hand){
    int ranks[5];
    int pairs[2] = {0,0};

    int i = 0;
    int pairsIndex = 0;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
    }

    for(i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j){
                continue;
            }
            else if(ranks[i] == ranks[j]){
                for(int k = 0; k < 2; k++){
                    if(pairs[k] == ranks[j]){
                        break;
                    }
                }
                pairs[pairsIndex] = ranks[i];
                pairsIndex++;
            }
        }
    }
    for(int j = 0; j < 2; j++){
        if(pairs[j] == 0){
            return 0;
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


