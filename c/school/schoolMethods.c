#include "project.h"

Student *HEAD = NULL;
Student *TAIL = NULL;

void printMenu(){

    printf("\n-=-=-=-=MENU-=-=-=-=\n1)Add Student\n2)Display School\n3)Delete student\n4)Find student\n5)Create School\n6)Exit program");

}

school *createSchool(){

    school *newSchool = (school *)malloc(sizeof(school));
    int numChars;
    do{
        printf("\nPlease enter the number of characters the name will be\n");
    }while(scanf("%d",&numChars) != 1);

    newSchool->name = (char *)malloc(sizeof(char) * numChars+1);

    do{
        printf("\nPlease enter the name of the school with enough characters less than or equal to the amount previously specified\n");
    }while(scanf("%s",newSchool->name) != 1);

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
        printf("\n(%d)Student %d : %s\n",tempHead->idNum,count++,tempHead->name);
        tempHead = tempHead->next;
    }

}

void removeHead(){

    if(HEAD->next != NULL){

        Student *tempNext = HEAD->next;
        HEAD->next = NULL;
        tempNext->prev = NULL;
        HEAD = NULL;
        HEAD = tempNext;
    }
    else{
        HEAD = NULL;
    }

}

void removeTail(){

    if(TAIL->prev != NULL){

        Student *prevNode = TAIL->prev;
        prevNode->next = NULL;
        TAIL->prev = NULL;
        TAIL = NULL;
        TAIL = prevNode;

    }
    else{
        TAIL = NULL;
    }

}

void deleteStudent(int theId){

    if(HEAD == NULL || TAIL == NULL){
        printf("\nYou are attempting to delete a student when the linked list is empty\n");
        return;
    }
    else if(HEAD->idNum == theId){
        removeHead();
    }
    else if(TAIL->idNum == theId){
        removeTail();
    }
    else{

        Student *tempHead = HEAD;
        while(tempHead != NULL){
            if(tempHead->idNum == theId){
                Student *prevNode = tempHead->prev;
                tempHead->prev = NULL;
                prevNode->next = tempHead->next;
                tempHead->next->prev = prevNode;
                tempHead->next = NULL;
                tempHead = NULL;
                return;
            }
        }
        printf("\nThe student was not found\n");
        return;

    }

}

int findStudent(int theId){

    Student *tempHead = HEAD;
    int index = 0;
    while(tempHead != NULL){
        if(tempHead->idNum == theId){
            return index;
        }
        index++;
        tempHead = tempHead->next;
    }
    printf("\nThe student could not be found\n");
    return -1;

}

void pop(){

    removeTail();

}

void push(school *theSchool, Student *theStudent){

    addStudent(theSchool,theStudent);

}

int numStudents(){

    Student *tempHead = HEAD;
    int count = 0;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;

}