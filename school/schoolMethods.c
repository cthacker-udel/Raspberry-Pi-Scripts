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

void seedRandom(){

    srand(time(NULL));

}

void addStudent(school *theSchool, Student *newStudent){

    if(HEAD == NULL || TAIL == NULL){
        HEAD = newStudent;
        TAIL = newStudent;
        theSchool->linkHead = HEAD;
        theSchool->attendance = 1;
    }
    else{

        TAIL->next = newStudent;
        newStudent->prev = TAIL;
        newStudent->next = NULL;
        TAIL = newStudent;
        theSchool->attendance++;

    }

}

Student *createStudent(){

    Student *newStudent = (Student *)malloc(sizeof(Student));

    int nameChars;

    do{
        printf("\nPlease enter the number of characters the student's name will be\n");
    }while(scanf("%d",&nameChars) != 1);

    newStudent->name = (char *)malloc(sizeof(char) * nameChars);

    do{
        printf("\nPlease enter the name of the student with only enough characters less than or equal to the amount specified previously\n");
    }while(scanf("%s",newStudent->name) != 1);

    do{
        printf("\nPlease enter the age of the student\n");
    }while(scanf("%d",&newStudent->age) != 1);

    do{
        printf("\nPlease enter the height of the student in centimeters\n");
    }while(scanf("%d",&newStudent->height) != 1);

    do{
        printf("\nPlease enter the grade level of the student\n");
    }while(scanf("%d",&newStudent->grade) != 1);

    newStudent->idNum = rand() % 999;

    newStudent->next = NULL;

    newStudent->prev = NULL;

    return newStudent;


}

void displaySchool(school *theSchool){

    printf("\nDisplaying the school : %s [attendance : %d]\n",theSchool->name,theSchool->attendance);
    Student *tempHead = theSchool->linkHead;
    int count = 1;
    while(tempHead != NULL){
        printf("\nStudent %d : %s\n",count++,tempHead->name);
        tempHead = tempHead->next;
    }

}