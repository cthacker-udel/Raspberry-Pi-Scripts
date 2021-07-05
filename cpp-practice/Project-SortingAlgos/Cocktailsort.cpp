#include <iostream>
using namespace std;

class Cocktailsort{

    void cocktailSort(int *,int);

};


void Cocktailsort::cocktailSort(int *arr, int len){

    bool loopVar = false;
    while(1){

        for(int i = 0,j=len-1; i < len-1 && j >= 1; i++,j--){
            if(*(arr+i) > *(arr+i+1)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
                loopVar = false;
            }
            else if(*(arr+j) < *(arr+j-1)){
                int temp = *(arr+j);
                *(arr+j) = *(arr+j-1);
                *(arr+j-1) = temp;
                loopVar = false;
                break;
            }
            else{
                loopVar = true;
            }
        }
        if(loopVar){
            break;
        }

    }

}