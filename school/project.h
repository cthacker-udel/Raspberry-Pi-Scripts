#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct theStudent{

    char *name;
    int age;
    int height;
    char *school;
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

school *createSchool();

Student *createStudent();

void deleteStudent(int);

int findStudent(int);

void pop();

void push(school *, Student *);