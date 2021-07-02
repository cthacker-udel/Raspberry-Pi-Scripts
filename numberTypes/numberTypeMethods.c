#include "project.h"

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

int isAbundant(int number){

    int sum = 0;
    int sqrtNumber = sqrt(number)+1;
    for(int i = 1; i < sqrtNumber; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    return sum > number? 1: 0;


    return 0;
}