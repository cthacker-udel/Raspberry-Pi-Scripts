#include "treat.h"

int eat_candy(treat *treats, int len){

    int total = 0;
    for(int i = 0; i < len; i++){
        treat theTreat = *(treats+i);
        total += theTreat.calories;
    }
    return total;

}