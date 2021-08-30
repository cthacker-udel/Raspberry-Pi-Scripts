#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(void){

    srand(time(NULL));
    board *theboard = makeBoard();
    // board constructed
    int x = 0;
    int y = 0;
    int boolVal = 0;
    makeStartFinish(theboard);
    for(int i = 0; i < theboard->size; i++){
        
        char theChar = *(*(theboard->theboard+i)+0);
        if(theChar == 'S'){
            x = i;
            break;
        }

        /*
        for(int j = 0; j < theboard->size; j++){

            char theChar = *(*(theboard->theboard+i)+j);
            if(theChar == 'E'){
                y = i;
                boolVal = 1;
                break;
            }

        }
        if(boolVal){
            break;
        }
        */

    }
    // found x and y of start
    while(1){
        // print strength
        printf("\n------------------------\nCURRENT STRENGTH : %d\n------------------------\n",theboard->player1->strength);
        printBoard(theboard);
        char choice;
        int res;
        do{
            printf("Choose a direction: (Uu)p\\(Dd)own\\(Ll)eft\\(Rr)ight");
        }while(scanf(" %c",&choice) == 0 && choice != 'U' && choice != 'D' && choice != 'L' && choice != 'R' && choice != 'u' && choice != 'd' && choice != 'l' && choice != 'r');

        if(choice == 'U' || choice == 'u'){

            res = movePiece(x,y,1,theboard->player1,theboard,0);
            if(res == 0){
                // do not move piece
                printf("\nInvalid Move!\n");
            }
            else{
                printf("\nMoving piece up\n");
                movePiece(x,y,1,theboard->player1,theboard,1);
                x--;
            }

        }
        else if(choice == 'D' || choice == 'd'){

            res = movePiece(x,y,3,theboard->player1,theboard,0);

            if(res == 0){
                // do not move piece
                printf("\nInvalid Move!\n");
            }
            else{
                printf("\nMoving piece down\n");
                movePiece(x,y,3,theboard->player1,theboard,1);
                x++;
            }

        }
        else if(choice == 'L' || choice == 'l'){

            res = movePiece(x,y,4,theboard->player1,theboard,0);

            if(res == 0){

                // do not move piece
                printf("\nInvalid Move!\n");
            }
            else{
                printf("\nMoving piece left\n");
                movePiece(x,y,4,theboard->player1,theboard,1);
                y--;

            }

        }
        else if(choice == 'R' || choice == 'r'){

            res = movePiece(x,y,2,theboard->player1,theboard,0);

            if(res == 0){

                // do not move piece
                printf("\nInvalid Move!\n");

            }
            else{
                printf("\nMoving piece right\n");
                movePiece(x,y,2,theboard->player1,theboard,1);
                y++;

            }

        }

    }

    return 0;
}
