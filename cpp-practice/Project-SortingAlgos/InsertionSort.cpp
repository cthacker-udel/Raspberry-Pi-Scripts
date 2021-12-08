#include "InsertionSort.hpp"

InsertionSort::InsertionSort(){


}

int *craftNewArray(int *arr, int len, int element, int index){

	int *newArr = new int[len];
	int i = 0;
	int tmp = 0;
	while(i < len){

		if(i == index){
			*(newArr+i) = element;
			i++;
			*(newArr+i) = *(arr+tmp++);
			i++;
		}
		else{
			*(newArr+i) = *(arr+tmp++);
			i++;
		}

	}
	return newArr;


}


void printArray(int *arr, int len){

	for(int i = 0; i < len; i++){
		cout << "arr[" << i << "] = " << *(arr+i) << " ,";
	}
	cout << endl;

}

void InsertionSort::sort(int *arr, int len){

    bool loopBool = false;
    bool foundElem = false;
    while(!loopBool){

        for(int i = 1; i < len; i++){

            int currElem = *(arr+i); // get current elem trying to swap
            int prevElem = *(arr+(i-1)); // get previous element

            if(currElem < prevElem){ // if element is out of order
            	loopBool = false;
                while(prevElem > currElem){ // while curr elem is out of order
                    for(int j = i-1; j >= 0; j--){ // cycle through predecessors trying to find right spot
                        prevElem = *(arr+j); // cycle through prev elements
                        if(currElem > prevElem){ // found spot where prev element is less than currelem
                            // found spot
                        	arr = craftNewArray(arr,len,currElem,j);
                        	foundElem = true;
                            /**(arr+i) = NULL; // assign orig number we are swapping in array to null
                            int *newArr = new int[len]; // construct new array with elements moved 1 up
                            for(int x = 0; x < len; x++){ // stop at spot we are swapping and place element there
                                if(*(arr+x) == NULL){
                                    // found element moving
                                    *(newArr+x) = *(arr+(x-1));
                                }
                                if(x == j){
                                    *(newArr+x) = currElem;
                                }
                            }*/
                        }
                    }
                    if(!foundElem){
                    	arr = craftNewArray(arr,len,currElem,0);
                    	foundElem = false;
                    }
                    printArray(arr,len);
                    break;
                    // element is placed at start of arr

                }

            }
            else{
            	loopBool = true;
            }

        }

    }


}
