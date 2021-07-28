#include "Board.hpp"


Board::Board(){

    this->size = 8;
    this->board = new char[size][size];

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

    this->size = newSize;
    this->board = new char[size][size];

}