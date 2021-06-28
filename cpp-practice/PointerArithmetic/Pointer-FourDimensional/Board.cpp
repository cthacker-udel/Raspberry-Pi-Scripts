#include "Board.hpp"

Board::Board(){

    size1 = 4;
    size2 = 4;
    size3 = 4;
    size4 = 4;

    int ****board = new int***[size1];
    *(board+0) = new int**[size2];
    *(*(board+0)+0) = new int*[size3];
    *(*(*(board+0)+0)) = new int[size4];

}


Board::Board(int newSize1, int newSize2, int newSize3, int newSize4){

    size1 = newSize1;
    size2 = newSize2;
    size3 = newSize3;
    size4 = newSize4;

    int ****board = new int***[size1];
    *(board+0) = new int**[size2];
    *(*(board+0)+0) = new int*[size3];
    *(*(*(board+0)+0)+0) = new int[size4];

}

Board::~Board(){

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                delete []*(*(*(board+i)+j)+k);
            }
            delete []*(*(board+i)+j);
        }
        delete []*(board+i);
    }
    delete []board;

}

void Board::createBoard(){

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                for(int l = 0; l < size4; l++){
                    *(*(*(*(board+i)+j)+k)+l) = i*j*k*l;
                }
            }
        }
    }

}

void Board::setBoard(int ****newBoard){
    board = newBoard;
}

int Board::sumBoard(){

    int sum = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                for(int l = 0; l < size4; l++){
                    sum += *(*(*(*(board+i)+j)+k)+l);
                }
            }
        }
    }
    return sum;

}

int Board::evenCount(){

    int count = 0;

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                for(int l = 0; l < size4; l++){
                    int number = *(*(*(*(board+i)+j)+k)+l);
                    if(number % 2 == 0){
                        count++;
                    }
                }
            }
        }
    }
    return count;

}

int Board::oddCount(){

    int count = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                for(int l = 0; l < size4; l++){
                    int value = *(*(*(*(board+i)+j)+k)+l);
                    if(value % 2 != 0){
                        count++;
                    }
                }
            }
        }
    }
    return count;

}

int Board::primeCount(){

    int count = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                for(int l = 0; l < size4; l++){
                    int value = *(*(*(*(board+i)+j)+k)+l);
                    if(isPrime(value)){
                        count++:
                    }
                }
            }
        }
    }
    return count;

}

bool Board::isPrime(int number){
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

void Board::printBoard(){

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            for(int k = 0; k < size3; k++){
                cout << "[ ";
                for(int l = 0; l < size4; l++){
                    cout << *(*(*(*(board+i)+j)+k)+l) << ", ";
                }
                cout << " ] " << endl;
            }
        }
    }

}

void Board::setCoord(int x1, int x2, int x3, int x4,int value){

    while(1){
        if(x1 < 0 || x1 > size1 || x2 < 0 || x2 > size2 || x3 < 0 || x3 > size3 || x4 < 0 || x4 > size4){
            printf("\n-=-=-=Enter valid coordinates(Curr coords : %d,%d,%d,%d)-=-=-=\n",x1,x2,x3,x4);
            printf("x1:");
            scanf("%d",&x1);
            printf("x2:");
            scanf("%d",&x2);
            printf("x3:");
            scanf("%d",&x3);
            printf("x4:");
            scanf("%d",&x4);
        }
        else{
            break;
        }
    }
    *(*(*(*(board+x1)+x2)+x3)+x4) = value;

}