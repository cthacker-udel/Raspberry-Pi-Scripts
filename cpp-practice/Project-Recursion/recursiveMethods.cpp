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
    return 1;

}

int sumDigits(int number){
    if(number < 10){
        return number;
    }
    else{
        return number % 10 + sumDigits(number / 10);
    }
}

int maxNum = 0;

int largestArr(int *arr, int len){

    
    if(len <= 1){
        if(*arr > maxNum){
            maxNum = *arr;
            return maxNum;
        }
        else{
            return maxNum;
        }
    }
    else{
        if((*arr+len-1) > maxNum){
            maxNum = *(arr+len-1);
            largestArr(arr,len-1);
        }
        else{
            largestArr(arr,len-1);
        }
    }
    return 1;

}

void reverseString(string theString){

    if(theString.length() == 1){
        cout << theString;
    }
    else{
        cout << theString.at(theString.length()-1);
        reverseString(theString.substr(0,theString.length()-1));
    }

}


int factorial(int number){
    if(number == 1){
        return 1;
    }
    else{
        return number * factorial(number-1);
    }
}

void printBinary(int number){

    string res;
    while(number != 0){
        int remainder = number % 2;
        number = number / 2;
        res += to_string(remainder);
    }
    for(int i = res.length()-1; i >= 0; i--){
        cout << res.at(i);
    }
    cout << endl;

}

bool isPrime(int number, int numberCopy){

    if(numberCopy == 1){
        cout << number << " is prime!" << endl;
        return true;
    }
    else if(number % numberCopy == 0){
        cout << number << " is not prime!" << endl;
        return false;
    }
    else{
        return isPrime(number,numberCopy-1);
    }


}