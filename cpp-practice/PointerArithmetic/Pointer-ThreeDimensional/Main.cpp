#include "Matrix.cpp"

int main(void){

    Matrix matrix(3,3,3);
    matrix.createMatrix();
    matrix.printMatrix();
    int sum = matrix.sumMatrix();
    int avg = matrix.avgMatrix();
    int sub = matrix.subMatrix();
    int evenCount = matrix.evenCount();
    int oddCount = matrix.oddCount();
    int primeCount = matrix.primeCount();

    cout << "\nSUM : " << sum << "\nAVG : " << avg << "\nSUB : " << sub << "\nEVENCOUNT : " << evenCount << "\nODDCOUNT : " << oddCount << "\nPRIMECOUNT : " << primeCount << endl;

}