#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mediaObj{

    char *name;
    char *kind;
    int duration;

}media;

int total_duration(media *,int);

int count_not_long(media *,int);

int take_until_long(media *,int);

char *longest_kind(media *,int);

int same_kind_of_media(media *,int);