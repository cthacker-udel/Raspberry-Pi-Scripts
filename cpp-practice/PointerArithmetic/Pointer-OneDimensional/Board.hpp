#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Board{

    int *board;

    public:

        Board();

        int *getBoard();

        void setBoard(int *);


}