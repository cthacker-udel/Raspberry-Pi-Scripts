#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Board{

    int *board;
    int size;

    public:

        Board();

        Board(int);

        ~Board();

        int *getBoard();

        void setBoard(int *);

        void craftBoard();

        int sumBoard();

        int evenCount();

        int oddCount();
        
        int primeCount();

        bool isPrime(int);

        void printBoard();

        void setCoord(int,int);

        void getCoords();




}