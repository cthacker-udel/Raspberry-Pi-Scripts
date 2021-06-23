#include "Board.hpp"


int main(void){

    Board board;
    int **theBoard = board.getBoard();
    // initializing 10 rows
    for(int i = 0; i < 10; i++){
        *(*(theBoard+i)) = i+1;
    }

    for(int i = 0; i < 10; i++){
        cout << *(*(theBoard+i)) << endl;
    }

}