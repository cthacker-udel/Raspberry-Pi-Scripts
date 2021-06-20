#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int max = 0;
int index = 0;
void largestElementArray(int *arr, int size){

        int number = *arr;
            printf("\nNumber = %d",number);
                if(index == size){
                           return;
                               }
                    if(*arr > max){
                                    max = *arr;
                                        }
                        index++;
                            largestElementArray(*(arr+1),size);


}


int main(){

        //printNaturalNumbers(1);
        //    //int res = sumOfNumbers(5);
        //        //printf("\nSum of numbers from 1 to 5 : %d",res);
        //            //printf("\n\n");
        //                //res = fib(10);
        //                    //printf("%d ",res);
        //                        //int *arr = makeArray(5);
        //                            //printArrayElems(arr,5);
        //                                int number = 192;
        //                                    printf("The number of digits in %d is : %d",number,countDigits(number));
        //                                        printf("\n\nThe sum of %d's digits is : %d\n",number,sumDigits(number));
        //
        //                                            //int num1 = 10;
        //                                                //int num2 = 50;
        //                                                    //printf("The gcd of %d and %d is : %d",num1,num2,gcd(num1,num2));
                                                                int arr[3] = {10,2,299};
                                                                    largestElementArray(arr,3);
        
                                                                    }



