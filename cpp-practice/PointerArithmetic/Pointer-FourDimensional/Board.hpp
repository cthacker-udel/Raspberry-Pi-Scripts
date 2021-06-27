#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Board{

    int ****board;
    int size1;
    int size2;
    int size3;
    int size4;

    public:

        Board();

        Board(int,int,int,int);

        ~Board();

        void createBoard();

        void setBoard(int ****);

        int sumBoard();

        int evenCount();

        int oddCount();

        int primeCount();

        bool isPrime(int);

        void printBoard();

        void setCoord(int,int,int,int);


};