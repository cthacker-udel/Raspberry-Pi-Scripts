#include "card.h"
#include <stdlib.h> // for drand48
#include <stdio.h>
#include <string.h>
 
/* This main() is constructed just for testing purposes. See
 * play_game() below for actually connecting together the pieces */

// Don't be afraid of writing "scaffolding code" like this: yes, it will be
// removed at the end, but that doesn't make it a waste of effort!
int main(int argc, char *argv[]) {
    // the below "seeds" the random number generator with the first argument
    // given to the program. I.e. "./game 5" will always play with the same
    // shuffle, and "./game 99" will play with a different shuffle. Leave this
    // in your final code for testing.
    if(argc>1) {
        srand48(atol(argv[1]));
    }
    play_game();
    return 0;
 }

// organize all the helper functions to play a complete game
void play_game(void) {
    cardT *pile = makeDeck();
    for(int i = 0; i < 7; i++){
        pile = shuffle(pile);
    }

    /*
     * Beginning of game
     *
     */

    cardT *userPile;
    cardT *dealerPile;
    userPile = deal(pile);
    userPile->next = deal(pile);
    dealerPile = deal(pile);
    printf("\nYour hand :  ");
    showPile(userPile);
    printf("\nDealer hand :  ");
    showPile(dealerPile);
    int playerStood = 0;
    int dealerTotal = 0;
    int userTotal = 0;

    char *answer = (char *)malloc(sizeof(char) * 6);
    printf("\nHit or Stand (h/s)?\n");
    while(scanf("%s",answer)){
            printf("\n");
            if(strcmp(answer,"hit") == 0 || strcmp(answer,"h") == 0 || strcmp(answer,"H") == 0){
                cardT *userTmp = userPile;
                while(userTmp->next != NULL){
                    userTmp = userTmp->next;
                }
                userTmp->next = deal(pile);
                userTotal = totalPile(userPile);
                showPile(userPile);
                if(userTotal > 21){
                    printf("\nLost! Your hands score was : %d and it went over 21!",totalPile(userPile));
                    return;
                }
                else if(userTotal == 21){
                    break;
                }
                else{
                    printf("\nYour total : %d\n",userTotal);
                    printf("Hit or Stand (h/s)?\n");
                }
            }
            else if(strcmp(answer,"s") == 0 || strcmp(answer,"S") == 0 || strcmp(answer,"stand")){
                break;
            }
    }
    printf("\nDealers turn\n");
    int iteration = 1;
    while(1){
         cardT *tmpDealerPile = dealerPile;
         while(tmpDealerPile->next != NULL){
             tmpDealerPile = tmpDealerPile->next;
         }
         tmpDealerPile->next = deal(pile);
         printf("\nDealers hand :  ");
         showPile(dealerPile);
         printf("\n\n");
         int dealerTotal = totalPile(dealerPile);
         if(dealerTotal >= 17 && dealerTotal <= 21){
             if(dealerTotal > userTotal){
                 printf("Dealer wins - hand has greater value then yours!\nTheir hand :  ");
                 showPile(dealerPile);
                 printf("\nDealer total : %d",totalPile(dealerPile));
                 printf("\nYour hand :  ");
                 showPile(userPile);
                 printf("\nYour total :  %d",totalPile(userPile));
                 return;
             }
             else if(dealerTotal == userTotal){
                 printf("Dealer wins - hand has equal value to yours!\nTheir hand :  ");
                 showPile(dealerPile);
                 printf("\nDealer total :  %d",totalPile(dealerPile));
                 printf("\nYour hand :  ");
                 showPile(userPile);
                 printf("\nYour total :  %d",totalPile(userPile));
                 return;
             }
             else{ 
                 printf("You win!\nDealers hand :  ");
                 showPile(dealerPile);
                 printf("\nYour hand :  ");
                 showPile(userPile);
                 return;
             }
         }
         else if(dealerTotal > 21){
            printf("You win!\nDealers hand :  ");
            showPile(dealerPile);
            printf("\nYour hand :  ");
            showPile(userPile);
            return;
         }
    }
}

