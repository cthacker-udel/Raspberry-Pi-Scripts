#include "Board.hpp"


bool Board::placePiece(int x, int y, Player *thePlayer){

    bool result = checkPiece(x,y,thePlayer);

    if(result){
        *(*(this->board+x)+y) = thePlayer->piece;
        return true;
    }
    else{
        return false;
    }

}

int Board::checkDirection(int direction, int x, int y,Player *thePlayer){

}



bool Board::checkPiece(int x, int y, Player *thePlayer){
    

    char thePiece = *(*(board+x)+y);
    const char player1Piece = this->player1->piece;
    const char player2Piece = this->player2->piece;


    switch(thePiece){

        case '?':{
            // valid placement
            return true;
            break;
        }
        case player1Piece:{
            if(thePlayer == this->player1){
                // invalid placement
                return false;
            }
            else{
                // invalid placement -- cannot place on top of piece
                return false;
            }
            break;
        }
        case player2Piece:{

            if(thePlayer == this->player2){
                // invalid placement
                return false;
            }
            else{
                // invalid placement -- cannot place on top of piece
                return false;
            }

        }
        default:{
            return false;
        }


    }    
    


}

Board::Board(){

    this->size = 8;
    this->board = new char[size][size];

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            *(*(this->board+i)+j) = '?';

        }

    }

    int answer;

    cout << "Enter how many players(Max 2)" << endl;
    cin >> answer;
    switch(answer){

        case 2:{

            string player1Name = "";
            char player1Piece = ' ';

            do{

                cout << "Enter Player1's Name" << endl;
                cin >> player1Name;

            }while(player1Name.length() == 0);

            do{

                cout << "Enter Player1's Piece" << endl;
                cin >> player1Piece;

            }while(player1Piece == ' ');


            string player2Name = "";
            char player2Piece = ' ';

            do{

                cout << "Enter Player2's Name" << endl;
                cin >> player2Name;

            }while(player2Name.length() == 0);

            do{

                cout << "Enter Player2's Piece" << endl;
                cin >> player2Piece;

            }while(player2Piece == ' ');

            this->player1 = new Player(player1Name,player1Piece);
            this->player2 = new Player(player2Name,player2Piece);

            break;
        }

        case 1:{

            string player1Name = "";
            char player1Piece = ' ';

            do{

                cout << "Enter Player1's Name" << endl;
                cin >> player1Name;

            }while(player1Name.length() == 0);

            do{

                cout << "Enter Player1's Piece" << endl;
                cin >> player1Piece;

            }while(player1Piece == ' ');

            this->player1 = new Player(player1Name,player1Piece);


            this->player2 = new Player("computer2",'C');

            break;
        }

        case 0:{

            this->player1 = new Player("computer1",'X');
            this->player2 = new Player("computer2",'O');

            break;
        }

        default:{
            cout << "Malformed input" << endl;
            break;
        }

    }


}


Board::Board(int newSize){

    if(newSize < 4){
        newSize = 4;
    }

    this->size = newSize;
    this->board = new char[size][size];


    for(int i = 0; i < this->size; i++){

        for(int j = 0; j < this->size; j++){

            *(*(board+i)+j) = '?';

        }

    }

    int answer;

    cout << "Enter how many players(Max 2)" << endl;
    cin >> answer;
    switch(answer){

        case 2:{

            string player1Name = "";
            char player1Piece = ' ';

            do{

                cout << "Enter Player1's Name" << endl;
                cin >> player1Name;

            }while(player1Name.length() == 0);

            do{

                cout << "Enter Player1's Piece" << endl;
                cin >> player1Piece;

            }while(player1Piece == ' ');


            string player2Name = "";
            char player2Piece = ' ';

            do{

                cout << "Enter Player2's Name" << endl;
                cin >> player2Name;

            }while(player2Name.length() == 0);

            do{

                cout << "Enter Player2's Piece" << endl;
                cin >> player2Piece;

            }while(player2Piece == ' ');

            this->player1 = new Player(player1Name,player1Piece);
            this->player2 = new Player(player2Name,player2Piece);

            break;
        }

        case 1:{

            string player1Name = "";
            char player1Piece = ' ';

            do{

                cout << "Enter Player1's Name" << endl;
                cin >> player1Name;

            }while(player1Name.length() == 0);

            do{

                cout << "Enter Player1's Piece" << endl;
                cin >> player1Piece;

            }while(player1Piece == ' ');

            this->player1 = new Player(player1Name,player1Piece);


            this->player2 = new Player("computer2",'C');

            break;
        }

        case 0:{

            this->player1 = new Player("computer1",'X');
            this->player2 = new Player("computer2",'O');

            break;
        }

        default:{
            cout << "Malformed input" << endl;
            break;
        }

    }

}