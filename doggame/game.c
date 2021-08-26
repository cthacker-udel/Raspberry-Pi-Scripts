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
    int y;
    int boolVal = 0;
    for(int i = 0; i < theboard->size; i++){

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

    }
    // found x and y of start
    while(1){

        char choice;
        int res;
        do{
            printf("Choose a direction: (U)p\\(D)own\\(L)eft\\(R)ight");
        }while(scanf(" %c",&choice) == 0 && choice != 'U' && choice != 'D' && choice != 'L' && choice != 'R');

        if(choice == 'U'){

            res = movePiece()

        }

    }

    return 0;
}