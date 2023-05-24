#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct theStudent{

    char *name;
    int age;
    int height;
    int grade;
    int idNum;
    struct theStudent *next;
    struct theStudent *prev;


}Student;


typedef struct theSchool{

    char *name;
    int attendance;
    Student *linkHead;

}school;

void addStudent(school *,Student *);

void printMenu();

school *createSchool();

Student *createStudent();

void displaySchool(school *);

void deleteStudent(int);

void removeHead();

void removeTail();

int findStudent(int);

void pop();

void push(school *,Student *);

int numStudents();