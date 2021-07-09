#include "costume.h"

int count_costumes(costume *costumes,int len){

    return len;

}


int total_price(costume *costumes,int len){

    int total = 0;
    for(int i = 0; i < len; i++){

        costume theCostume = *(costumes+i);
        total += theCostume.price;

    }
    return total;

}