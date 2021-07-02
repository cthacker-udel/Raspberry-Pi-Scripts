#include "project.h"


int aaSize;

int isPrime(int number){

    if(number < 0){
        return 0;
    }
    else if(number < 2){
        return 1;
    }
    else if(number == 2 || number == 3 || number == 5){
        return 1;
    }
    else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
        return 0;
    }
    else{
        int sqrtNumber = sqrt(number);
        for(int i = 2; i < sqrtNumber; i++){
            if(number % i == 0){
                return 0;
            }
        }
        return 1;
    }


}

int isEven(int number){

    return number % 2 == 0? 1: 0;

}

int isOdd(int number){

    return number % 2 != 0? 1 : 0;

}

int numFactors(int number){
    int numFactors = 0;
    for(int i = 1; i < number; i++){
        if(number % i == 0){
            numFactors++;
        }
    }
    return numFactors;
}

int *getFactors(int number){

    int *factors = (int *)malloc(sizeof(int) * numFactors(number));

    int index = 0;
    for(int i = 1; i < number; i++){
        if(number % i == 0){
            *(factors+index) = i;
            index++;
        }
    }
    return factors;

}

int sumFactors(int number){

    int sum = 0;
    for(int i = 1; i < number; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    return sum;

}

int *compute_subset_sums(int *a, int n){

    int *aa = (int *)calloc(1ULL << n,sizeof(int));
    aaSize = 1ULL << n;
    if(aa != NULL){

        for(size_t i = 0; (i >> n) == 0; i++){

            int sum = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    sum += a[j];
                }
            }
            aa[i] = sum;

        }

    }
    return aa;

}

int isDeficient(int number){

    int two_n = number * 2;

}


int isWeird(int number){

    if(isAbundant(number)){
        int *factors = getFactors(number);
        int *arr = compute_subset_sums(factors,numFactors(number));
        for(int i = 0; i < aaSize; i++){
            if(*(arr+i) == number){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }

}

int isAbundant(int number){

    int sum = 0;
    for(int i = 1; i < number; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    return sum > number? 1: 0;


    return 0;
}