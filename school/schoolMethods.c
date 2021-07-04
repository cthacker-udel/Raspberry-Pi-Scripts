#include "project.h"

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


    newSchool->next = NULL;
    newSchool->prev = NULL;
    newSchool->attendance = 0;
    printf("\nSchool has been created successfully\n");
    return newSchool;

}