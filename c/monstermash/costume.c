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


char *most_expensive_costume(costume *costumes, int len){

    int theMaxPrice = max_price(costumes,len);

    char *maxName;
    for(int i = 0; i < len; i++){

        costume theCostume = *(costumes+i);
        if(theCostume.price == theMaxPrice){
            maxName = theCostume.label;
        }

    }
    return maxName;

}

char *find_last_medium(costume *costumes, int len){

    for(int i = len-1; i >= 0; i--){

        costume theCostume = *(costumes+i);
        if(theCostume.numMedium > 0){
            return theCostume.label;
        }

    }
    return "";


}

char *find_first_small(costume *costumes, int len){

    for(int i = 0; i < len; i++){

        costume theCostume = *(costumes + i);
        if(theCostume.numSmall > 0){
            return theCostume.label;
        }

    }
    return "";

}