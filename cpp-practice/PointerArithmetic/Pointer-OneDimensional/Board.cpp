#include "Board.hpp"


Board::Board(){

    size = 4;

}

Board::Board(int newSize){

    size = newSize;

}

Board::~Board(){

    delete []board;

}

void Board::craftBoard(){

    board = new int[size];

}

int Board::sumBoard(){

    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(board+i);
    }
    return sum;

}

void Board::setBoard(int *newBoard){
    board = newBoard;
}

int *Board::getBoard(){

    return board;

}