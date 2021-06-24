#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

class Board{

    int **board;
    int size;

    public:

        Board();
        
        Board(int);

        int **getBoard();

        void setBoard(int **);

        int sumBoard();

        int evenCount();

        int oddCount();

        int primeCount();

        int **craftBoard();


};