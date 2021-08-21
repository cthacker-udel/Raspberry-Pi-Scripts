#include "board.h"

board *makeBoard(){

    int size;
    char piece;

    board *theboard = malloc(sizeof(board));

    printf("\nEnter the board size: lowest is 4");
    scanf("%d",&size);
    theboard->theboard = malloc(sizeof(char*) * size);
    for(int i = 0; i < size; i++){

        *(theboard->theboard+i) = malloc(sizeof(char) * size);

    }
    // initializing the board

    player *player1 = createPlayer();
    player *player2 = createPlayer();

    printf("\nEnter default piece to fill board with");
    scanf(" %c",&piece);

    theboard->defaultPiece = piece;
    theboard->size = size;
    theboard->player1 = player1;
    theboard->player2 = player2;

    return theboard;

}

void makeStartFinish(board *theboard){

    int randomX = rand() % theboard->size; // set y to 0
    int randomY = rand() % theboard->size; // set y to size-1

    *(*(theboard->theboard+randomX)+0) = 'E';
    *(*(theboard->theboard+randomY)+theboard->size-1) = 'F'; 

}

void printBoard(board *theboard){

    for(int i = 0; i < theboard->size; i++){
        for(int j = 0; j < theboard->size; j++){
            printf(" %c ",*(*(theboard->theboard+i)+j));
        }
    }

}

int movePiece(int x, int y, int direction, player *theplayer, board *theboard, int moveThePiece){

    /*

    1 - North
    2 - East
    3 - South
    4 - West

    */

   switch(direction){

       case 1:{ // north

           if(x == 0){
               // already at top of map
               return 0;
           }
           else{

               char upperChar = *(*(theboard->theboard+x+1)+y);
                if(upperChar == '|' || upperChar == '-'){
                    // wall, ask if they want to spend strength
                }
                else if(upperChar == 'F'){
                    // food - player gains strength
                    int randGain = (rand() % theplayer->strength)+1;
                    printf("\nYou stepped on food so you gain %d strength",randGain);
                    if(moveThePiece){
                        theplayer->strength += randGain;
                    }
                }
                else if(upperChar == 'T'){
                    // trap - player loses strength
                    if(moveThePiece){
                        int randLoss = (rand() % (theplayer->strength / 2))+1;
                        theplayer->strength -= randLoss;
                        printf("You lost %d strength, that brings your strength to : %d",randLoss,theplayer->strength);
                        if(theplayer->strength <= 0){
                            printf("\nYou have lost the game, your strength reached 0");
                            return 0;
                        }
                        else{
                            return 1;
                        }
                    }
                }
                else{
                    // empty spot, valid move
                    return 1;
                }

           }

           break;
       }

       case 2:{ // east
           break;
       }

       case 3:{ // south
           break;
       }

       case 4:{ // west
           break;
       }

       default:{
           return;
       }


   }

}


player *getPlayer1(board *theboard){

    return theboard->player1;

}

player *getPlayer2(board *theboard){

    return theboard->player2;

}

int getSize(board *theboard){

    return theboard->size;

}

char getDefPiece(board *theboard){

    return theboard->defaultPiece;

}

void setDefPiece(char thePiece, board *theboard){

    theboard->defaultPiece = thePiece;

}

