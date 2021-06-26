#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <ctype.h>
using namespace std;

class Matrix{

    int ***board;
    int size1;
    int size2;
    int size3;

    public:

        Matrix();

        Matrix(int,int,int);

        ~Matrix();

        int sumMatrix();

        int avgMatrix();

        int subMatrix();

        int evenCount();

        int oddCount();

        int primeCount();

        bool isPrime(int);

        




};