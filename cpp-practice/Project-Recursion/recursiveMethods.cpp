#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

int calcSumToN(int n){

    if(n == 0){
        return 0;
    }
    else{
        return n + calcSumToN(n-1);
    }


}

int fib(int n){

    if(n <= 0){
        return 0;
    }
    else{
        return fib(n-1) + fib(n-2);
    }


}

void printArr(int *arr, int len){

    if(len == 0){
        cout << *arr << endl;
    }
    else{
        cout << *(arr+len-1);
        printArr(arr,len-1);
    }

}

int countDigits(int number){

    if(number < 10){
        return 1;
    }
    else{
        return 1 + countDigits(number / 10);
    }

}

int gcd(int number1, int number2){

    if(number1 == number2){
        return number1;
    }
    if(number1 > number2){
        gcd(number1 - number2,number2);
    }
    else if(number2 > number1){
        gcd(number1,number2 - number1);
    }

}

int sumDigits(int number){
    if(number < 10){
        return number;
    }
    else{
        return number % 10 + sumDigits(number / 10);
    }
}