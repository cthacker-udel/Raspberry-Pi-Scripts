#include "Board.hpp"


Board::Board(){

    size = 4;
    board = new int*[size];

}

Board::Board(int newSize){

    size = newSize;
    board = new int*[size];

}

void Board::createBoard(){
    
    int number = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            *(*(board+i)+j) = number;
            number++;
        }
    }

}

void Board::printBoard(){
    cout << "Value should be from 0 - " << (size*size)-1 << "\n\n" << endl;
    cout << "[ ";
    for(int i = 0; i < size; i++){
        cout << "[ ";
        for(int j = 0; j < size-1; j++){
            cout << *(*(board+i)+j) << ", ";
        }
        cout << *(*(board+i)+size-1) << " ]," << endl;
    }

}

Board::~Board(){

    for(int i = 0; i < size; i++){

        delete []*(board+i);

    }

}

int **Board::getBoard(){

    return board;

}

/*
void Board::printBoard(){

    for(int i = 0; i < size; i++){
        cout << "Row " << i << " : ";
        for(int j = 0; j < size; j++){

            cout << *(*(board+i)+j) << ",";

        }
        cout << endl;
    }

}
*/

void Board::getCoords(){

    int x;
    int y;
    int value;

    // verifying x coordinate

    while(true){

        cout << "\nEnter a x coordinate\n" << endl;
        cin >> x;
        if(x < 0 || x >= size){
            cout << "\nPlease enter a valid coordinate between 0-" << size-1 << endl;
            continue;
        }
        break;

    }

    // verifying y coordinate

    while(true){

        cout << "\nEnter a y coordinate\n" << endl;
        cin >> y;
        if(y < 0 || y >= size){
            cout << "\nPlease enter a valid coordinate between 0-" << size-1 << endl;
            continue;
        }
        break;

    }

    cout << "\nEnter a value to put into the array\n" << endl;
    cin >> value;
    setCoord(x,y,value);
}

void Board::setCoord(int x, int y, int value){
    *(*(board+x)+y) = value;
}

int Board::sumBoard(){

    int sum = 0;
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){
        
            sum += *(*(board+i)+j);
        
        }

    }
    return sum;

}

int Board::evenCount(){

    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int value = *(*(board+i)+j);
            if(value % 2 == 0 && value != 0){
                count++;
            }
        }
    }
    return count;

}

int Board::oddCount(){

    int count = 0;

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            int value = *(*(board+i)+j);
            if(value % 2 != 0){
                count++;
            }

        }

    }
    return count;

}

int Board::primeCount(){

    int count = 0;

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            int value = *(*(board+i)+j);
            if(isPrime(value)){
                count++;
            }

        }

    }
    return count;

}

bool Board::isPrime(int number){

    if(number < 0){
        return false;
    }
    else if(number < 2){
        return true;
    }
    else if(number == 2 || number == 3 || number == 5){
        return true;
    }
    else{

        int theSqrt = sqrt(number);
        for(int i = 0; i < theSqrt; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;


    }

}


/*
void Board::craftBoard(){

    board = new int*[size];

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            *(*(board+i)+j) = j;

        }

    }

}
*/


void Board::setBoard(int **newBoard){

    newBoard = board;

}