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