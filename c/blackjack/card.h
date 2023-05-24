// note, the typedef name is "cardT", the struct name is "struct card"
typedef struct card {
    int rank;
    char suit;
    struct card *next; // Be sure you understand what data type "next" is
} cardT;

// Used something like this:
// cardT *pile = createCard(2,'C');
// pile->next = createCard(3,'C');
// pile->next->next = NULL;

cardT *makeCard(int rank, char suit); // will need to allocate space!
cardT *makeDeck();
void freePile(cardT *pile);
cardT *shuffle(cardT *pile); // provided for you
cardT* deal(cardT *pile);
int totalPile(cardT *pile);
int countPile(cardT *pile);  // provided for you
void showPile(cardT *pile);
void play_game(void);
