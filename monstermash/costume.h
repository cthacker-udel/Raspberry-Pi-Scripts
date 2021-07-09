#include <string.h>

typedef struct theCostume{

    char *label;
    int price;
    char **sizes;

}costume;

int count_costumes(costume *,int);

int total_price(costume *,int);

int count_sizes(costume *,int);

int max_price(costume *,int);

char *most_expensive_costume(costume *,int);

char *find_last_medium(costume *,int);

char *find_first_small(costume *,int);