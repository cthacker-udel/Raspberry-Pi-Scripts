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
    while(1){

        

    }

    return 0;
}