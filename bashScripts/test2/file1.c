#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>


typedef struct person{

    char *name;
    char *street;

}ID;

void basic_pointer_print(){

    int m = 10;
    int n = 20;
    int *z;

    z = &m;
    printf("\nz stores the address of m = %p\n",z);
    printf("\n*z stores the value of m = %d\n",*z);

    printf("\n&m is the address of m = %p\n",&m);

    printf("\n&n stores the address of n = %p\n",&n);


}

int pointerAddTwo(int *a, int *b){
    return *a + *b;    
}

int maxTwoPointer(int *a, int *b){
    return *a > *b? *a : *a < *b? *b : *a;
}


void changePosition(char *ch1, char *ch2)
{
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}
void charPermu(char *cht, int stno, int endno)
{
   int i;
   if (stno == endno)
     printf("%s  ", cht);
   else
   {
       for (i = stno; i <= endno; i++)
       {
          changePosition((cht+stno), (cht+i));
          charPermu(cht, stno+1, endno);
          changePosition((cht+stno), (cht+i)); 
       }
   }
}


int largestElemDyanmic(int *arr, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(*(arr+i) > max){
            max = *(arr+i);
        }
    }
    return max;
}

int lengthOfString(char *str){

    int length = 0;
    for(int i = 0; str[i] != '\0'; i++){
        length++;
    }
    return length;

}

int swap(int *a , int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int factorial(int *number){
    if(*number < 3){
        return *number;
    }
    else{
        int oneLess = *number - 1;
        return *number * factorial(&oneLess);
    }
}

void numberOfChars(char *str){

    char vowels[] = "aeiouAEIOU";

    int vowelCount = 0;
    int consonantCount = 0;

    for(int i = 0; i < strlen(str); i++){
        char currChar = *(str+i);
        if(strchr(vowels,currChar)){
            vowelCount++;
        }
        else{
            consonantCount++;
        }
    }
    printf("\nThe word : %s has %d vowels and %d consonants",str,vowelCount,consonantCount);

}

void arraySort(int *arr, int size){

    int loopvar = 0;

    printf("\nThe elements of the array before sorting are :\n");
    for(int i = 0; i < size; i++){
        int number = *(arr+i);
        printf("%d ",number);
    }

    while(1){

        for(int i = 0; i < size-1; i++){
            int number = *(arr+i);
            int number2 = *(arr+i+1);
            if(number > number2){
                int tmp = number;
                *(arr+i+1) = number;
                *(arr+i) = number2;
                loopvar = 1;
                break;
            }
            else{
                loopvar = 0;
            }
        }
        if(!loopvar){
            break;
        }
    }

    printf("\n\n The elements of the array after sorting are : \n");
    for(int i = 0; i < size; i++){
        int number = *(arr+i);
        printf("%d ",number);
    }


}

int *maxPointer(int *a, int *b){
    return *a > *b? a: *b > *a? b: a;
}



int main(void){

    ID *johnson = (ID *)malloc(sizeof(ID));
    johnson->name = (char *)malloc(sizeof(char) * 30);
    strcpy(johnson->name,"John Alter");
    johnson->street = (char *)malloc(sizeof(char) * 100);
    strcpy(johnson->street, "Court Street");
    printf("%s from %s",johnson->name,johnson->street);
    ID *names = (ID *)malloc(sizeof(ID) * 10);
    int idNum = 1;
    for(int i = 0; i < 10; i++){
        (names+i)->name = (char *)malloc(sizeof(char) * 30);
        (names+i)->street = (char *)malloc(sizeof(char) * 100);
        char name[30];
        char street[100];
        printf("\nEnter in a name for ID #%d",idNum);
        fgets(name,30,stdin);
        printf("\nEnter in a street for ID#%d",idNum++);
        fgets(street,100,stdin);
        (names+i)->name = name;
        (names+i)->street = street;
        printf("\nID ENTERED : %s from %s\n",(names+i)->name,(names+i)->street);
    }

}

