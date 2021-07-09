typedef struct theMonster{

    char *name;
    char *kind;
    int spookyiness;
    int undead;


}monster;


int count_monsters(monster *,int);

int count_undead_monsters(monster *,int);

float average_spookiness(monster *,int);

float average_undead_spookiness(monster[],int);

int count_spooky_monsters(monster[],int);

int count_vampires(monster[],int);