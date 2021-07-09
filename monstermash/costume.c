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

int count_sizes(costume *costumes, int len){

    int total = 0;
    for(int i = 0; i < len; i++){

        costume theCostume = *(costumes+i);

        total += theCostume.numSmall + theCostume.numMedium + theCostume.numLarge + theCostume.numXL + theCostume.numXXL;

    }
    return total;

}

int max_price(costume *costumes, int len){

    int max_price = 0;
    for(int i = 0; i < len; i++){

        costume theCostume = *(costumes+i);
        if(max_price < theCostume.price){
            max_price = theCostume.price;
        }

    }
    return max_price;

}