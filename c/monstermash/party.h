typedef struct theParty{

    char *type;
    int werewolves;
    int vampires;
    int witches;

}party;


int sum_guests(party);

int were_only_werewolves(party);

int total_folks(party);

char *check_party_size(party);

float check_party_ratio(party);