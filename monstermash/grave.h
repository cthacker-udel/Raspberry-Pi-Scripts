#include <string.h>
#include <ctype.h>

typedef struct theGrave{

    char *name;
    char *message;

}grave;

int count_grave_all(grave *,int);

int count_grave_characters(grave *,int);

int estimate_grave_cost(grave *,int);

int count_shouters(grave *,int);