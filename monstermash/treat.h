#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct theTreat{

    char *name;
    int chocolate;
    int calories;
    int quantity;

}treat;


int eat_candy(treat *,int);

float find_most_calorific_ratio(treat *,int);

char *find_most_calorific(treat *,int);

int count_chocolates(treat *,int);

int get_choco_quantity(treat *,int);