#include <stdlib.h>
#include <iostream>
using namespace std;


class Bubblesort{

    void bubbleSort(int *,int);

};

void Bubblesort::bubbleSort(int *arr, int len){

    bool loopVar = false;
    while(true){

        for(int i = 0; i < len-1; i++){
            if(*(arr+i) > *(arr+i+1)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
                loopVar = false;
                break;
            }
            else{
                loopVar = true;
            }
        }

    }


}