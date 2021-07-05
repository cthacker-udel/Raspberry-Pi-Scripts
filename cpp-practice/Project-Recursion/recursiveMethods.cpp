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