#include "checkers.h"

pi_joystick_t *joystick = NULL;

int delay = 100;

int xCoord;

int yCoord;

int turn;

checkersPiece *playerCURR;

checkersPiece *computerCURR;


void coinFlip(){
    time_t t;
    srand((unsigned)time(&t));
    int flipNum = rand();
    if(flipNum % 2 == 0){
        turn = 1; // Opponent's turn
    }
    else{
        turn = 0; // Player's turn
    }
    if(turn == 1){
        computerCURR = getComputerTeam();
        currCursor(computerCURR);
    }
    else{
        playerCURR = getPlayerTeam();
        currCursor(playerCURR);

    }
}


checkersPiece *getPlayerCURR(){
    return playerCURR;
}

checkersPiece *getComputerCURR(){
    return computerCURR;
}


void handler(unsigned int code){
   
    checkersPiece *tempHead; 
    switch(code){
        case KEY_UP:
            fprintf(stderr,"Pressed up");
            if(turn == 0){
                
            }
            break;
        case KEY_DOWN:
            fprintf(stderr,"Pressed down");
            break;
        case KEY_LEFT:
            fprintf(stderr,"Pressed left");
            break;
        case KEY_RIGHT:
            fprintf(stderr,"Pressed right");
            break;
        case KEY_ENTER:
            fprintf(stderr,"Pressed Enter");
            break;
    }

}






void openJoystick(void){
    if(joystick == NULL){
        joystick = getJoystickDevice();
    }
}

void closeJoystick(void){
    if(joystick){
        freeJoystick(joystick);
        joystick = NULL;
    }
}


void checkJoystick(void){
    pollJoystick(joystick,handler,delay);
}

int getTurn(){
    return turn;
}
