/*
 * @author - Cameron Thacker
 *
 */

#include "project.h"

int min(int,int);

int max(int,int);

int evalHand(pokerCard *hand){
    if(countCards(hand) == 5 && royalFlush(hand)){
        return 1;
    }
    else if(countCards(hand) == 5 && straightFlush(hand)){
        return 2;
    }
    else if(countCards(hand) >= 4 && fourOfAKind(hand)){
        return 3;
    }
    else if(countCards(hand) == 5 && fullHouse(hand)){
        return 4;
    }
    else if(countCards(hand) == 5 && isFlush(hand)){
        return 5;
    }
    else if(countCards(hand) == 5 && isStraight(hand)){
        return 6;
    }
    else if(countCards(hand) >= 3 && isThreePair(hand)){
        return 7;
    }
    else if(countCards(hand) >= 4 && isTwoPair(hand)){
        return 8;
    }
    else if(countCards(hand) >= 2 && isPair(hand)){
        return 9;
    }
    else{
        return 10;
    }
}


int royalFlush(pokerCard *hand){
    if(allSameSuit(hand)){
        if(allAlternating(hand)){
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
        int firstRank = ranks[i];
        int secondRank = ranks[i+1];
        maxNum = max(firstRank,secondRank);
    }
}

int straightFlush(pokerCard *hand){
    if(allSameSuit(hand)){
        if(allAlternating(hand)){
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


int fourOfAKind(pokerCard *hand){
    int numCards = countCards(hand);
    int ranks[numCards];

    int i = 0;
    pokerCard *tempHead = hand;
    while(tempHead != NULL){
        ranks[i] = tempHead->rank;
        tempHead = tempHead->next;
        i++;
    }

    for(int i = 0; i < numCards; i++){
        int currRank = ranks[i];
        int count = 1;
        for(int j = 0; j < numCards; j++){
            if(j == i){
                continue;
            }
            else{
                if(ranks[j] == currRank){
                    count++;
                }
                else{
                    continue;
                }
            }
        }
        if(count == 4){
            return 1;
        }
        else{
            count = 1;
        }
    }
    return 0;
}

int fullHouse(pokerCard *hand){
    int numCards = countCards(hand);
    int ranks[numCards];

    int x = 0;
    pokerCard *tempHead = hand;
    while(tempHead != NULL){
        ranks[x] = tempHead->rank;
        x++;
        tempHead = tempHead->next;
    }
    int noDups[numCards];
    int dupFound = 0;

    for(int i = 0; i < numCards; i++){
        noDups[i] = 0;
    }

    int dupIndex = 0;

    for(int i = 0; i < numCards; i++){
        int currNumber = ranks[i];
        for(int j = 0; j < numCards; j++){
            if(noDups[j] == currNumber){
                dupFound = 0;
                break;
            }
            dupFound = 1;
        }
        if(dupFound){
            noDups[dupIndex] = currNumber;
            dupIndex++;
        }
    }

    fprintf(stderr,"\nPrinting noDups\n");
    for(int i = 0; i < numCards; i++){
        fprintf(stderr,"\t %d ",noDups[i]);
    }

    int count = 0;
    int threeOfAKindFound = 0;
    int pairFound = 0;
    for(int i = 0; i < numCards; i++){
        if(noDups[i] != 0){
            int currNumber = noDups[i];
            for(int j = 0; j < numCards; j++){
                int currRanksNumber = ranks[j];
                if(currRanksNumber == currNumber){
                    count++;
                }
            }
            if(count == 3){
                fprintf(stderr,"Three of a kind found");
                noDups[i] = 0;
                threeOfAKindFound = 1;
                count = 0;
            }
            else if(count == 2){
                fprintf(stderr,"Two of a kind found");
                noDups[i] = 0;
                pairFound = 1;
                count = 0;
            }
            else{
                count = 0;
            }
        }
    }
    if(threeOfAKindFound && pairFound){
        return 1;
    }
    else{
        return 0;
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
        int firstRank = ranks[i];
        int secondRank = ranks[i+1];
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
    fprintf(stderr,"\nEntering allsamesuit\n");
    char *suit = hand->suit;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        fprintf(stderr,"\nsuit == %s and tempHand->suit == %s",suit,tempHand->suit);
        if(strcmp(suit,tempHand->suit) != 0){
            return 0;
        }
        tempHand = tempHand->next;
    }
    return 1;
}

int allAlternating(pokerCard *hand){

    fprintf(stderr,"\nEntering isAllAlternating\n");

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
    
    
    fprintf(stderr,"\nPrinting sorted array for isAllAlternating\n");
    for(int i = 0; i < numCards; i++){
        fprintf(stderr,"%d,",ranks[i]);
    }
    

    for(int i = 0; i < numCards-1; i++){
        int firstNum = ranks[i];
        int secondNum = ranks[i+1];
        if(fabs(firstNum - secondNum) == 1){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;

}

int isFlush(pokerCard *hand){
    
    fprintf(stderr,"\nentering isFlush\n");

    char suits[6][10];
    
    pokerCard *tempHand = hand;
    
    int i = 0;
    while(tempHand != NULL){
        suits[i][0] = tempHand->suit;
        i++;
        tempHand = tempHand->next;
    }
    //fprintf(stderr,"\nBefore isFlush forLoop\n");
    for(int j = 0; j < 6; j++){
        for(int k = 0; k < 6; k++){
            //fprintf(stderr,"\ninside inner for loop isFlush\n");
            if(k == j){
                continue;
            }
            else{
                //fprintf(stderr,"\nsuits[j] == %s and suits[k] == %s",suits[j],suits[k]);
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

int isStraight(pokerCard *hand){
    if(allAlternating(hand)){
        return 1;
    }
    else{
        return 0;
    }
}

int isThreePair(pokerCard *hand){
    
    int numOfCards = countCards(hand);
    int ranks[numOfCards];

    int i = 0;
    pokerCard *tempHand = hand;

    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
    }

    int count = 0;
    for(i = 0; i < numOfCards; i++){
        for(int j = 0; j < numOfCards; j++){
            if(i == j){
                continue;
            }
            else if(ranks[i] == ranks[j]){
                //fprintf(stderr,"ranks[i] == %d and ranks[j] == %d",ranks[i],ranks[j]);
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

void printRanks(int ranks[], int len){
    fprintf(stderr,"\nThe ranks are : \n");
    int loopvar = 0;
    while(1){
        for(int i = 0; i < len-1; i++){
            int currVar = ranks[i];
            int forwardVar = ranks[i+1];
            if(currVar > forwardVar){
                ranks[i] = forwardVar;
                ranks[i+1] = currVar;
                loopvar = 0;
                break;
            }
            loopvar = 1;
        }
        if(loopvar){
            break;
        }
    }
    for(int i = 0; i < len; i++){
        fprintf(stderr,"%d,",ranks[i]);
    }
}

int isTwoPair(pokerCard *hand){
    int numCards = countCards(hand);
    int ranks[numCards];
    int pairs[2] = {0,0};

    int i = 0;
    int pairsIndex = 0;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
        i++;
    }

    printRanks(ranks,numCards);

    int loopController = 0;

    for(i = 0; i < numCards; i++){
        for(int j = 0; j < numCards; j++){
            if(i == j){
                continue;
            }
            else if(ranks[i] == ranks[j]){
                for(int k = 0; k < 2; k++){
                    //fprintf(stderr,"\npairs[k] = %d and ranks[j] = %d",pairs[k],ranks[j]);
                    if(pairs[k] == ranks[j]){
                        loopController = 0;
                        break;
                    }
                    loopController = 1;
                }
                if(loopController){
                    //fprintf(stderr,"Assiging pairs[%d] to %d",pairsIndex,ranks[i]);
                    pairs[pairsIndex] = ranks[i];
                    pairsIndex++;
                    loopController = 0;
                }
            }
        }
    }
    for(int j = 0; j < 2; j++){
        //fprintf(stderr,"\nITER %d\n",pairs[j]);
        if(pairs[j] == 0){
            //fprintf(stderr,"\nreached if---\n");
            return 0;
        }
        //printf("\npairs == %d",pairs[j]);
    }
    return 1;
}




int isPair(pokerCard *hand){
    
    int numOfCards = countCards(hand);
    int ranks[numOfCards];
    
    int i = 0;
    pokerCard *tempHand = hand;
    while(tempHand != NULL){
        ranks[i] = tempHand->rank;
        tempHand = tempHand->next;
        i++;
    }


    for(i = 0; i < numOfCards; i++){
        for(int j = 0; j < numOfCards; j++){
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


