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

int isAmicable(int num1, int num2){

    int *factorsNum1 = getFactors(num1);

    int *factorsNum2 = getFactors(num2);

    int *sum_factors_num1 = compute_subset_sums(factorsNum1,numFactors(num1));

    int subsetLen = aaSize;

    int *sum_factors_num2 = computer_subset_sums(factorsNum2,numFactors(num2));

    int subset2Len = aaSize;

    int isSumNum2 = 0;

    int isSumNum1 = 0;

    for(int i = 0; i < subsetLen; i++){

        if(*(sum_factors_num1) == num2){
            isSumNum2 = 1;
            break;
        }

    }

    for(int i = 0; i < subset2Len; i++){

        if(*(sum_factors_num2) == num1){
            isSumNum1 = 1;
        }

    }

    if(isSumNum2 && isSumNum1){

        return 1;

    }
    else{

        return 0;

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

int isHappy(int number){

    int sum = 0;
    while(number != 1){

        while(number > 9){
            int rightDigit = number % 10;
            sum += (rightDigit * rightDigit);
            number = number / 10;
        }
        sum += (number * number);
        number = sum;
        sum = 0;

    }
    return 1;


}

int isHarshad(int number){

    int origNumber = number;
    int sum = 0;
    while(number > 9){

        int rightDigit = number % 10;
        sum += rightDigit;
        number = number / 10;


    }
    sum += number;
    return origNumber % sum == 0? 1: 0;

}

int isKaprekar(int number){

    char numberStr[100];
    sprintf(numberStr,"%d",number);
    const int numDigits = strlen(numberStr);
    int square = number*number;
    char squareStr[100];
    sprintf(squareStr,"%d",square);
    char leftSide[numDigits];
    char rightSide[numDigits];
    for(int i = 0; i < numDigits; i++){
        leftSide[i] = squareStr[i];
    }
    for(int i = strlen(squareStr)-1, j = 0; j < numDigits; j++,i--){
        rightSide[j] = squareStr[i];
    }
    long numOne = strtoumax(leftSide,(char **)NULL,10);
    long numTwo = strtoumax(rightSide,(char **)NULL,10);
    return numOne + numTwo == number;

}

int isFactorion(int number){
    
    int origNumber = number;
    int sum = 0;
    while(number > 9){
        int rightDigit = number % 10;
        sum += factorial(rightDigit);
        number = number / 10;
    }
    sum += factorial(number);
    return sum == origNumber? 1: 0;

}

int isEquivalent(int number1, int number2){

    if(sumFactors(number1) == sumFactors(number2)){

        return 1;

    }
    else{

        return 0;

    }

}

int isComposite(int number){

    if(!isPrime(number)){
        return 1;
    }
    else{

        return 0;

    }

}

int isCircular(int number){

    if(number % 10 == 0 || number % 10 == 1 || number % 10 == 5 || number % 10 == 6){

        return 1;

    }
    else{

        return 0;

    }

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
    int sumOfFactors = sumFactors(number);
    if(sumOfFactors < two_n){
        return 1;
    }
    else{
        return 0;
    }
}

int numberLength(int number){

    int count = 0;
    while(number > 9){
        number = number / 10;
        count++;
    }
    count++;
    return count;


}

int isAutomorphic(int number){

    int square = number*number;
    int numLength = numberLength(square);
    char *squareStr = (char *)malloc(sizeof(char) * numLength+1);
    char *endStr = (char *)malloc(sizeof(char) * numberLength(number)+1);
    sprintf(squareStr,"%d",square);
    sprintf(endStr,"%d",number);
    int startIndex = strlen(squareStr)-1;
    for(int i = strlen(endStr)-1; i >= 0; i--){
        char findStr = *(endStr+i);
        char findStrSq = *(squareStr+startIndex);
        if(findStr != findStrSq){
            return 0;
        }
        else{
            startIndex--;
        }
    }
    return 1;

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

int catalanNumber(int u_n){

    return factorial(2*u_n) / factorial(u_n+1)*factorial(u_n);

}

int isCircular(int number){

    return number % 10 == 0 || number % 10 == 1 || number % 10 == 5 || number % 10 == 6;

}