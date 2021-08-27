#include "Card.hpp"
#include <list>

/*

add deal implementation


*/

class Hand{

    list<Card> hand;

    public:

        Hand(list<Card>);


        Card *deal();

        list<Card *> dealN(int);

};