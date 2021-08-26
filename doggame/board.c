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

   /*

    Number codes:

    0 : invalid move
    1 : valid move/move completed


   */

   switch(direction){

       case 1:{ // north

           if(x == 0){
               // already at top of map
               return 0;
           }
           else{

               char upperChar = *(*(theboard->theboard+x-1)+y);
                if(upperChar == '|' || upperChar == '-'){
                    // wall, ask if they want to spend strength
                    int randCost = (rand() % theplayer->strength)-(rand() % theplayer->strength+2);
                    if(randCost < 0){
                        randCost = 0;
                    }
                    if(theplayer->strength <= randCost){
                        printf("\nAttempting to move through the wall would cost %d strength, and you do not have enough strength[CURR : %d]",randCost,theplayer->strength);
                        return 0;
                    }
                    else{
                        printf("\nYou are attempting to move through a wall, it will cost %d strength, you currently have %d strength",randCost,theplayer->strength);
                        char answer = ' ';
                        do{
                            printf("\nDo you want to move through the wall?(Y\\N)?");
                        }while(scanf("%d",&answer) && (answer != 'Y' && answer != 'N'));
                        // user answer
                        if(answer == 'N'){
                            // user answers no
                            return 0;
                        }
                        else{
                            if(moveThePiece){
                                theplayer->strength -= randCost;
                                *(*(theboard->theboard+x-1)+y) = theplayer->piece;
                                *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                            }
                            return 1;
                        }
                    
                    }

                }
                else if(upperChar == 'F'){
                    // food - player gains strength
                    if(moveThePiece){
                        int randGain = (rand() % theplayer->strength)+1;
                        printf("\nYou stepped on food so you gain %d strength",randGain);
                        theplayer->strength += randGain;
                    }
                    return 1;
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
                            *(*(theboard->theboard+x-1)+y) = theplayer->piece;
                            *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                            return 1;
                        }
                    }
                    return 1;
                }
                else{
                    // empty spot, valid move
                    if(moveThePiece){

                        *(*(theboard->theboard+x-1)+y) = theplayer->piece;
                        // successfully placed piece, 
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                        // successfully updated piece moving from

                    }
                    return 1;
                }

           }

           break;
       }

       case 2:{ // east, x stays same, y+1

            if(y == theboard->size-1){
                // end of board <--- right side
                return 0;
            }

            char iChar = *(*(theboard->theboard+x)+y+1);

            if(iChar == '|' || iChar == '-'){
                // wall ran into
                int randCost = (rand() % theplayer->strength)-(rand() % theplayer->strength+2);
                if(randCost < 0){
                    randCost = 1;
                }
                if(theplayer->strength <= randCost){
                    printf("\nAttempting to move through the wall would cost %d strength, and you do not have enough strength[CURR : %d]",randCost,theplayer->strength);
                    return 0;
                }
                else{
                    printf("\nYou are attempting to move through a wall, it will cost %d strength, you currently have %d strength",randCost,theplayer->strength);
                    char answer = ' ';
                    do{
                        printf("\nDo you want to move through the wall?(Y\\N)?");
                    }while(scanf("%d",&answer) && (answer != 'Y' && answer != 'N'));
                    // user answer
                    if(answer == 'N'){
                        // user answers no
                        return 0;
                    }
                    else{
                        if(moveThePiece){
                            theplayer->strength -= randCost;
                            *(*(theboard->theboard+x)+y+1) = theplayer->piece;
                            *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                        }
                        return 1;
                    }
                    
                }

            }
            else if(iChar == 'F'){
                // food acquired]
                if(moveThePiece){
                    int randAmt = rand() % theplayer->strength+3;
                    printf("\nYou stepped on food, and you gain %d strength!",randAmt);
                    *(*(theboard->theboard+x)+y+1) = theplayer->piece;
                    *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                    // successfully moved player
                }
                return 1;
            }
            else if(iChar == 'T'){
                // trap found
                if(moveThePiece){
                    int randAmt = rand() % theplayer->strength;
                    printf("\nYou stepped on a trap, and you lost %d strength!",randAmt);
                    theplayer->strength -= randAmt;
                    if(theplayer->strength <= 0){
                        // player has lost
                        theplayer->strength = 0;
                        printf("\nYou currently have %d strength, you lose!",theplayer->strength);
                        return 0;
                    }
                    else{
                        printf("\nYou currently have %d strength!",randAmt);
                        *(*(theboard->theboard+x)+y+1) = theplayer->piece;
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                        return 1;
                    }
                }
                return 1;
            }
            else{
                // valid move, empty space

                if(moveThePiece){
                    // update spaces
                    *(*(theboard->theboard+x)+y+1) = theplayer->piece;
                    *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                }
                return 1;

            }

           break;
       }

       case 3:{ // south, x+1, y same

            if(x == theboard->size-1){
                // edge of board
                return 0;
            }

            char theTile = *(*(theboard->theboard+x+1)+y);

            if(theTile == '|' || theTile == '-'){
                // trying to move into wall

                if(moveThePiece){

                    int randRequirement = rand() % theplayer->strength;

                    if(randRequirement <= 0){
                        randRequirement = 1;
                    }

                    if(randRequirement >= theplayer->strength){
                        printf("\nYou do not have enough strength to move through the wall");
                        return 0;
                    }

                    printf("\nThe cost to walk through the wall is : %d strength\n",randRequirement);

                    char answer = ' ';
                    do{
                        printf("\nDo you want to move through the wall?(Y/N), it will cost %d strength",randRequirement);
                    }while(scanf(" %c",&answer) == 0 && answer != 'Y' && answer != 'N');

                    if(answer == 'Y'){
                        // move through wall
                        *(*(theboard->theboard+x+1)+y) = theplayer->piece;
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                    }
                    else{

                        return 0;

                    }
                    return 1;
                }
                return 1;

            }
            else if(theTile == 'F'){
                // food tile
                if(moveThePiece){

                    int randAmt = rand() % theplayer->strength;
                    if(randAmt == 0){
                        randAmt = 2;
                    }
                    printf("\nYou stepped on a food tile, so you gain %d strength!",randAmt);
                    theplayer->strength += randAmt;
                    *(*(theboard->theboard+x+1)+y) = theplayer->piece;
                    *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                    return 1;
                }
                return 1;
            }
            else if(theTile == 'T'){
                // trap tile

                if(moveThePiece){
                    // steps on trap
                    int randAmt = rand() % theplayer->strength-3;
                    if(randAmt <= 0){
                        randAmt = 1;
                    }
                    printf("\nYou stepped on a trap!, so you lost %d strength!\n",randAmt);
                    theplayer->strength -= randAmt;
                    if(theplayer->strength <= 0){
                        // player loses
                        printf("By stepping on the trap, your health dropped to 0, you have lost!");
                        return 1;
                    }
                    else{
                        // player survives
                        printf("\nYou have survived the trap! Your current strength left is : %d",theplayer->strength);
                        *(*(theboard->theboard+x+1)+y) = theplayer->piece;
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                        return 1;
                    }
                }
                else{
                    return 1;
                }

            }
            else{
                // empty tile
                if(moveThePiece){
                    // change piece on board
                    *(*(theboard->theboard+x+1)+y) = theplayer->piece;
                    *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                    return 1;
                }
                return 1;
            }
           break;
       }

       case 4:{ // west, x same, y-1

            if(y == 0){

                // moving off of board
                return 0;

            }
            else{

                char iChar = *(*(theboard->theboard+x)+y-1);
                if(iChar == '|' || iChar == '-'){

                    // wall

                }
                else if(iChar == 'F'){

                    // food

                }
                else if(iChar == 'T'){

                    // trap
                    if(moveThePiece){
                    // steps on trap
                    int randAmt = rand() % theplayer->strength-3;
                    if(randAmt <= 0){
                        randAmt = 1;
                    }
                    printf("\nYou stepped on a trap!, so you lost %d strength!\n",randAmt);
                    theplayer->strength -= randAmt;
                    if(theplayer->strength <= 0){
                        // player loses
                        printf("By stepping on the trap, your health dropped to 0, you have lost!");
                        return 1;
                    }
                    else{
                        // player survives
                        printf("\nYou have survived the trap! Your current strength left is : %d",theplayer->strength);
                        *(*(theboard->theboard+x)+y-1) = theplayer->piece;
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;
                        return 1;
                    }
                }
                else{
                    return 1;
                }

                }
                else{

                    // empty spot

                    if(moveThePiece){

                        *(*(theboard->theboard+x)+y-1) = theplayer->piece;
                        *(*(theboard->theboard+x)+y) = theboard->defaultPiece;

                    }
                    return 1;

                }


            }


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

