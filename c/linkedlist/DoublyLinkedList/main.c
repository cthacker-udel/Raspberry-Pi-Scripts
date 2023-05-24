#include "project.h"
#include <math.h>

node *ROOT = NULL;
node *TAIL = NULL;

void addNode(int value){
    
    node *theNode = createNodeV2(value);
    if(ROOT == NULL){
        ROOT = theNode;
        TAIL = theNode;
    }
    else{
    
        // insert
        node *tempHead = ROOT;
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        } 
        tempHead->next = theNode;
        theNode->prev = tempHead;
        TAIL = theNode;
    }


}


node *createNode(){

    int val = -1;

    do{
        printf("\nEnter a integer value for val");
    }while(scanf("%d",&val) == 0);

    node *newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;


}

node *createNodeV2(int value){

    node *newNode = malloc(sizeof(node));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;

}


void removeTail(){

    if(TAIL == NULL){

        // there is no tail
        printf("\nLIST IS EMPTY, UNABLE TO REMOVE TAIL\n");

    }
    else{

        if(TAIL->prev == NULL){
            // tail is only node
            TAIL = NULL;
            ROOT = NULL;
        }
        else{
            node *prevNode = TAIL->prev;
            prevNode->next = NULL;
            TAIL->prev = NULL;
            TAIL = NULL;
            TAIL = prevNode;
        }

    }

}

void removeHead(){

    if(ROOT == NULL){
        // list is already empty
        printf("\nUnable to remove head, list is already empty\n");
    }
    else{

        if(ROOT->next == NULL){
            ROOT = NULL;
            TAIL = NULL;
        }
        else{

            node *nextNode = ROOT->next;
            ROOT->next = NULL;
            ROOT = NULL;
            nextNode->prev = ROOT;

        }

    }


}

int nodeCount(){

    int count = 0;
    node *tempHead = ROOT;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}

int findLastIndex(int value){

    if(ROOT == NULL){
        // list is empty
        return -1;
    }
    else if(ROOT->next == NULL){

        if(ROOT->val == value){
            return 0;
        }
        else{
            return -1;
        }

    }
    else{

        node *tempTail = TAIL;
        int ind = nodeCount()-1;
        while(tempTail != NULL){
            if(tempTail->val == value){
                return ind;
            }
            tempTail = tempTail->prev;
            ind--;
        }
        return -1;
    }

}

int findFirstIndex(int value){

    if(ROOT == NULL){
        // list is empty
        return -1;
    }
    else if(ROOT->next == NULL){

        if(ROOT->val == value){
            return 0;
        }
        else{
            return -1;
        }

    }
    else{

        int ind = 0;
        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val == value){
                return ind;
            }
            tempHead = tempHead->next;
            ind++;
        }
        return -1;


    }


}

int removeNode(int value){

    /*

    Passed value to delete, can use findfirst or findlast index, and a combination of
    nodeCount to judge the list length and operations to perform dependant on that

    returns the value of the node removed

    */

   if(ROOT == NULL){

       // empty list
       return -1;

   }
   else if(ROOT->val == value){

       removeHead();

   }
   else if(TAIL->val == value){

       removeTail();

   }

}


void insert(int index, int value){

    /*

        Takes a index and a value, value is used to construct the node, and the
        index is used to figure out where to place the node

    */

   if(ROOT == NULL){
       return;
   }
   else{
       node *newNode = (node *)malloc(sizeof(node));
       newNode->val = value;
       int numNodes = nodeCount();
       if(index <= 0){
           newNode->next = ROOT;
           newNode->prev = NULL;
           ROOT->prev = newNode;
       }
       else if(index >= (numNodes-1)){
           TAIL->next = newNode;
           newNode->prev = TAIL;
           TAIL = newNode;
       }
       else{

           int currIndex = 0;
           node *tempHead = ROOT;
           while(tempHead != NULL){

               if(currIndex == index){
                   node *prevNode = tempHead->prev;
                   node *nextNode = tempHead->next;
                   newNode->prev = prevNode;
                   newNode->next = nextNode;
                   nextNode->prev = newNode;
                   prevNode->next = newNode;
                   break;
               }
               tempHead = tempHead->next;
               currIndex++;

           }

       }
       
   }


}

void addTail(int value){

    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = value;

    if(ROOT == NULL){
        ROOT = newNode;
        TAIL = newNode;
    }
    else{
        TAIL->next = newNode;
        newNode->prev = TAIL;
        newNode->next = NULL;
        TAIL = newNode;
    }

}

void addHead(int value){

    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = value;

    if(ROOT == NULL){
        ROOT = newNode;
        TAIL = newNode;
    }
    else{
        newNode->next = ROOT;
        ROOT->prev = newNode;
        newNode->prev = NULL;
        ROOT = newNode;
    }

}



void moveUp(int value){

    /*

    Takes a value denoting which node to move, and if that node is the head, then
    that node becomes the tail and the node before it is the new head

    Different operations dependant on the size of the list

    */

   // first validate that value is in linked list

   node *tempHead = ROOT;

   if(ROOT == NULL){

       printf("\nThe head of the list is NULL\n");
       return;

   }
   int isInList = 0;
   int ind = 0;

   while(tempHead != NULL){
       if(tempHead->val == value){
           isInList = 1;
           break;
       }
       tempHead = tempHead->next;
       ind++;
   }

   if(isInList){
       // now move up
        if(ROOT->val == value){
            // head is the node to move up, make new tail
            int value = ROOT->val;
            removeHead();
            addTail(value);
        }
        else if(TAIL->val == value){
            // tail is the node to move up, reorder tail
            if(TAIL->prev == NULL){
                // only one node, stop execution
                return;
            }
            else{
                node *tailPrev = TAIL->prev;
                if(tailPrev->prev == NULL){
                    tailPrev->prev = TAIL;
                    tailPrev->next = NULL;
                    TAIL->next = tailPrev;
                    TAIL->prev = NULL;
                    TAIL = tailPrev;
                    return;
                }
                else{
                    node *tailPrevPrev = tailPrev->prev;
                    tailPrevPrev->next = TAIL;

                    // make tailPrev new Tail
                    tailPrev->prev = TAIL;
                    tailPrev->next = NULL;

                    TAIL->prev = tailPrevPrev;
                    TAIL->next = tailPrev;

                    TAIL = tailPrev;
                    return;
                }
            }
        }
        else{
            // node is in middle of list
            tempHead = ROOT;
            while(tempHead != NULL){
                if(tempHead->val == value){
                    break;
                }
                tempHead = tempHead->next;
            }
            node *tempHeadPrev = tempHead->prev;
            node *tempHeadPrevPrev = tempHead->prev->prev;

            tempHead->prev = tempHeadPrevPrev;

            tempHeadPrev->next = tempHead->next;

            tempHead->next->prev = tempHeadPrev;

            tempHeadPrev->prev = tempHead;

            tempHeadPrevPrev->next = tempHead;

            tempHead->next = tempHeadPrev;


        }
   }
   else{
       printf("\nNode is not in list\n");
       return;
   }


}

int exists(int value){

    // tests whether a node exists

    if(ROOT == NULL){
        return 0;
    }
    else{

        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val == value){
                return 1;
            }
            tempHead = tempHead->next;
        }
        return 0;

    }

}

void moveDown(int value){

    /*

    Takes a value denoting which node to move down, and if that node is the tail
    then that node becomes the head, and the operations change depending on the
    size of the list

    */

   if(ROOT == NULL){
       // list is empty
       printf("\nAttempting to insert at list when list is empty");
       return;
   }
   else if(ROOT->next == NULL){
       // list only has one node
       printf("\nAttempting to move node down when list only has one node");
       return;
   }

    node *tempHead = ROOT;
    if(exists(value)){
        // if node exists in list

        if(TAIL->val == value){
            // make node new head
            int tempVal = TAIL->val;
            removeTail();
            addHead(tempVal);
        }
        else if(ROOT-> val == value){
            // move head down
            int tempVal = ROOT->val;
            removeHead();
            int tempVal2 = ROOT->val;
            removeHead();
            addHead(tempVal);
            addHead(tempVal2);
        }

        while(tempHead != NULL){
            if(tempHead->val == value){

                // move node down
                tempHead->prev->next = tempHead->next;
                tempHead->next->prev = tempHead->prev;
                tempHead->prev = tempHead->next;
                tempHead->next->next->prev = tempHead;
                tempHead->next = tempHead->next->next;
                printf("\nNode successfully moved down");
                return;

            }
            tempHead = tempHead->next;
        }
    }
    else{
        printf("\nThe node does not exist in the list\n");
        return;
    }



}

int occurence(int value){

    int count = 0;

    node *tempHead = ROOT;
    while(tempHead != NULL){
        if(tempHead->val == value){
            count++;
        }
        tempHead = tempHead->next;
    }
    return count;

}

int* indexes(int value){

    int theCount = occurence(value);
    int *newArr = (int *)malloc(sizeof(int) * theCount);

    int ind = 0;
    int placeInd = 0;
    node *tempHead = ROOT;
    while(tempHead != NULL){
        if(tempHead->val == value){
            *(newArr+placeInd) = ind;
            placeInd++;
        }
        ind++;
        tempHead = tempHead->next;
    }
    return newArr;

}

int isUnique(int value){

    return occurence(value) == 1? 1: 0;

}

int isRepeating(int value){

    return occurence(value) > 1? 1: 0;

}

int swapValue(int origVal, int swapVal){

    if(ROOT == NULL){
        // list is empty
        return 0;
    }
    else if(occurence(origVal) < 1){
        return 0;
    }
    else{

        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val == origVal){
                tempHead->val = swapVal;
                return 1;
            }
            tempHead = tempHead->next;
        }
        return 0;

    }

}

int isPrime(int value){

    if(value <= 2){
        return 1;
    }
    else if(value == 2 || value == 3 || value == 5){
        return 1;
    }
    else if(value % 2 == 0 || value % 3 == 0 || value % 5 == 0){
        return 0;
    }
    else{

        int theRoot = (int)sqrt(value);
        for(int i = 2; i <= theRoot; i++){
            if(value % i == 0){
                return 0;
            }
        }
        return 1;

    }

}

int evenCount(){

    if(nodeCount(ROOT) == 0){
        return 0;
    }
    else{

        int cnt = 0;
        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val % 2 == 0){
                cnt++;
            }
            tempHead = tempHead->next;
        }
        return cnt;

    }

}

int oddCount(){

    if(nodeCount(ROOT) == 0){
        return 0;
    }
    else{

        int cnt = 0;
        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(tempHead->val % 2 != 0){
                cnt++;
            }
        }
        return cnt;

    }

}

int primeCount(){

    if(nodeCount(ROOT) == 0){
        return 0;
    }
    else{

        int cnt = 0;
        node *tempHead = ROOT;
        while(tempHead != NULL){
            if(isPrime(tempHead->val)){
                cnt++;
            }
            tempHead = tempHead->next;
        }
        return cnt;

    }

}

int isSortedAscending(){

    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, so unable to determine if list is sorted ascending\n");
    }
    else{

        while(tempHead->next != NULL){

            int nodeBefore = tempHead->val;
            tempHead = tempHead->next;
            int nodeAfter = tempHead->val;
            if(nodeBefore <= nodeAfter){
                continue;
            }
            else{
                return 0;
            }
        }
        return 1;

    }

}

int isSortedDescending(){

    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, so unable to determine if list is sorted descending\n");
    }
    else{

        while(tempHead->next != NULL){

            int nodeBefore = tempHead->val;
            tempHead = tempHead->next;
            int nodeAfter = tempHead->val;
            if(nodeAfter >= nodeBefore){
                continue;
            }
            else{
                return 0;
            }
        }
        return 1;

    }

}

int *toIntArray(){

    if(ROOT == NULL){
        printf("\nThe list is empty, so unable to convert list to array\n");
        return NULL;
    }
    else{

        int *values = (int *)malloc(sizeof(int) * nodeCount());
        node *tempHead = ROOT;
        for(int i = 0;tempHead != NULL;i++){

            *(values+i) = tempHead->val;

        }
        return values;

    }

}

int *bubbleSortArr(int *arr, int len){

    int loopVar = 0;
    while(1){

        for(int i = 0; i < len-1; i++){

            int currElem = *(arr+i);
            int forwardElem = *(arr+i+1);
            if(currElem > forwardElem){
                loopVar = 1;
                *(arr+i+1) = currElem;
                *(arr+i) = forwardElem;
            }
            else if(!loopVar){
                loopVar = 0;
            }
        }
        if(!loopVar){
            break;
        }

    }
    return arr;

}

void sort(){

    if(ROOT == NULL){
        printf("\nThe list is empty, so unable to sort the list via insertion sort\n");
        return;
    }
    else if(nodeCount() == 1){
        printf("\nThe list only contains one element, so unable to sort the list via insertion sort\n");
        return;
    }
    else{

        int *nodeValues = bubbleSortArr(toIntArray(),nodeCount());
        for(int i = 0; i < nodeCount(); i++){
            addTail(*(nodeValues+i));
        }

    }

}

void deleteList(){

    if(ROOT == NULL){
        // list is empty
    }
    else{
        node *tempDNode = ROOT;
        node *tempNode = ROOT;
        while(tempNode != NULL){
            tempNode = tempNode->next;
            free(tempDNode);
            tempDNode = tempNode;
        }
        // successfully cleared list!
    }

}

int *bubbleSortArr(int *arr, int len){

    int loopCondition = 1;
    while(loopCondition){

        for(int i = 0; i < len-1; i++){

            int elem1 = *(arr+i);
            int elem2 = *(arr+i+1);
            if(elem1 > elem2){

                *(arr+i+1) = elem2;
                *(arr+i) = elem2;
                loopCondition = 1;
                break;

            }
            else{
                loopCondition = 0;
            }

        }
        if(loopCondition){
            continue;
        }
        else{
            break;
        }

    }
    return arr;


}

void weightedEvenOrOdd(){

    int evenVal = evenCount();
    int oddVal = oddCount();

    if(evenVal > oddVal){
        printf("\nWeighted even");
    }
    else if(oddVal > evenVal){
        printf("\nWeighted odd");
    }
    else{
        printf("\nEvenly weighted list\n");
    }

}

int sumProperDivisors(int number){

    int total = 0;
    for(int i = 0; i < number; i++){
        if(number % i == 0){
            total += i;
        }
    }
    return total;

}

int abundantNumberCount(){

    int count = 0;
    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, unable to comute count");
        return;
    }
    else{
        while(tempHead != NULL){
            int value = tempHead->val;
            if(value < sumProperDivisors(value)){
                count += 1;
            }
            tempHead = tempHead->next;
        }
        return count;
    }

}

int deficientNumberCount(){

    int count = 0;
    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, unable to compute count");
        return;
    }
    else{
        while(tempHead != NULL){
            int value = tempHead->val;
            if(value > sumProperDivisors(value)){
                count += 1;
            }
            tempHead = tempHead->next;
        }
        return count;
    }

}

int automorphicNumberCount(){

    int count = 0;
    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, unable to compute automorphic number count");
        return;
    }
    else{

        while(tempHead != NULL){

            int value = tempHead->val;
            int theRoot = sqrt(value);
            if(theRoot % 10 == value % 10){
                count += 1;
            }

            tempHead = tempHead->next;
        }
        return count;

    }

}


int perfectNumberCount(){

    int count = 0;
    node *tempHead = ROOT;
    if(ROOT == NULL){
        printf("\nThe list is empty, unable to compute count");
        return;
    }
    else{
        while(tempHead != NULL){
            int value = tempHead->val;
            if(value == sumProperDivisors(value)){
                count++;
            }
        }
        return count;
    }

}

int factorial(int number){

	if(number <= 1){
		return number;
	}
	else{
		return number * factorial(number-1);
	}

}

int testCatalan(int number){

	int total = 1;
	for(int i = 1;total < number;i++){
		total = factorial(2*i) / (factorial(i+1)*factorial(i));
	}
	if(total == number){
		return 1;
	}
	else{
		return 0;
	}



}

int catalanNumberCount(){

	node *tempHead = ROOT;
	int count = 0;
	while(tempHead != NULL){
		if(testCatalan(tempHead->val)){
			count++;
		}
		tempHead = tempHead->next;
	}
	return count;

}

int circularNumberCount(){

	node *tempHead = ROOT;
	int count = 0;
	while(tempHead != NULL){
		int value = tempHead->val;
		if((value*value) % 10 == value){
			count++;
		}
		tempHead = tempHead->next;
	}
	return count;

}


int main(void){

    int *arr = (int *)malloc(sizeof(int) * 11);
    printf("\nAfter initializing array\n");
    for(int i = 10; i >= 0; i++){
        *(arr+i) = i;
    }
    arr = bubbleSortArr(arr,11);
    printf("\nPrinting the array\n");
    for(int i = 0; i < 11; i++){
        printf(" %d ",*(arr+i));
    }

}

