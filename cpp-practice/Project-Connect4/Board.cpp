#include "Board.hpp"


Board::Board(){

    this->size = 8;
    this->board = new char[size][size];

    int answer;

    cout << "Enter how many players(Max 2)" << endl;
    cin >> answer;
    switch(answer){

        case 2:
            break;

        case 1:
            break;

        case 0:
            break;

        default:
            cout << "Malformed input" << endl;
            break;

    }


}


Board::Board(int newSize){

    this->size = newSize;
    this->board = new char[size][size];

}