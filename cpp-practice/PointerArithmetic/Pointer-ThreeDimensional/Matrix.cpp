#include "Matrix.hpp"

Matrix::Matrix(){

    size1 = 4;
    size2 = 4;
    size3 = 4;
    board = new int**[size1];

}

Matrix::Matrix(int newSize1, int newSize2, int newSize3){

    this->size1 = newSize1;
    this->size2 = newSize2;
    this->size3 = newSize3;

    board = new int**[size1];

}

void Matrix::createMatrix(){

    int number = 0;

    for(int i = 0; i < size1; i++){
        *(board+i) = new int*[size1];
        for(int j = 0; j < size2; j++){
            *(*(board+i)+j) = new int[size2];
            for(int k = 0; k < size3; k++){
                *(*(*(board+i)+j)+k) = number;
                number++;
            }
        }
    }

}

void Matrix::printMatrix(){

    int value = size1 * size2 * size3;
    cout << "Matrix should have values up to " << value << endl;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                cout << *(*(*(board+i)+j)+k) << " , ";
            }
        }
    }
    cout << endl;

}

Matrix::~Matrix(){

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            delete []*(*(board+i)+j);
        }
        delete []*(board+i);
    }

}

int Matrix::sumMatrix(){

    int sum = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                sum += *(*(*(board+i)+j)+k);
            }
        }
    }
    return sum;

}

int Matrix::avgMatrix(){

    int totalNumbers = size1 * size2 * size3;
    int theSum = sumMatrix();
    return (theSum*1.0) / totalNumbers;

}

int Matrix::subMatrix(){

    int sum = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                sum -= *(*(*(board+i)+j)+k);
            }
        }
    }
    return sum;

}

int Matrix::evenCount(){

    int count = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                int value = *(*(*(board+i)+j)+k);
                if(value % 2 == 0){
                    count++;
                }
            }
        }
    }
    return count;

}

int Matrix::oddCount(){

    int count = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                int value = *(*(*(board+i)+j)+k);
                if(value % 2 != 0){
                    count++;
                }
            }
        }
    }
    return count;

}

bool Matrix::isPrime(int number){

    if(number < 2){
        return true;
    }
    else if(number == 2 || number == 3 || number == 5){
        return true;
    }
    else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
        return false;
    }
    else{
        int sqrtNumber = sqrt(number);
        for(int i = 2; i < sqrtNumber; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }

}

int Matrix::primeCount(){

    int count = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                int value = *(*(*(board+i)+j)+k);
                if(isPrime(value)){
                    count++;
                }
            }
        }
    }
    return count;

}

