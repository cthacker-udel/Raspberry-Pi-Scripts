#include "project.h"

Student *HEAD = NULL;
Student *TAIL = NULL;

school *createSchool(){

    school *newSchool = (school *)malloc(sizeof(school));
    int numChars;
    do{
        printf("\nPlease enter the number of characters the name will be\n");
    }while(scanf("%d",&numChars) != 1);

    newSchool->name = (char *)malloc(sizeof(char) * numChars+1);

    do{
        printf("\nPlease enter the name of the school with enough characters less than or equal to the amount previously specified\n");
    }while(scanf("%s",newSchool->name));

    newSchool->attendance = 0;
    printf("\nSchool has been created successfully\n");
    return newSchool;

}

void addStudent(school *theSchool, Student *newStudent){

    if(HEAD == NULL || TAIL == NULL){
        HEAD = newStudent;
        TAIL = newStudent;
        theSchool->linkHead = HEAD;
    }
    else{

        TAIL->next = newStudent;
        newStudent->prev = TAIL;
        newStudent->next = NULL;
        TAIL = newStudent;

    }


}