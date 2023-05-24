#include "treat.h"

int eat_candy(treat *treats, int len){

    int total = 0;
    for(int i = 0; i < len; i++){
        treat theTreat = *(treats+i);
        total += theTreat.calories;
    }
    return total;

}

float find_most_calorific_ratio(treat *treats, int len){

    float max = 0.0;
    for(int i = 0; i < len; i++){
        treat theTreat = *(treats+i);
        float ratio = theTreat.calories*1.0 / theTreat.quantity;
        max = fmax(max,ratio);
    }
    return max;

}

int count_chocolates(treat *treats, int len){

    int count = 0;
    for(int i = 0; i < len; i++){
        treat theTreat = *(treats+i);
        if(theTreat.chocolate){
            count++;
        }
    }
    return count;

}

int get_choco_quantity(treat *treats, int len){

    int total = 0;
    for(int i = 0; i < len; i++){
        treat theTreat = *(treats+i);
        if(theTreat.chocolate){
            total += theTreat.quantity;
        }
    }
    return total;

}