#include "checkers.h"

pi_joystick_t *joystick = NULL;

int delay = 100;

int xCoord;

int yCoord;

int turn;

checkersPiece *playerCURR;

checkersPiece *computerCURR;

checkersPiece *nextPiece;

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
   
    switch(code){
        case KEY_UP:
            fprintf(stderr,"Pressed up");
            if(turn == 0){ // computer's turn
                if(playerCURR->next != NULL){
                    playerCURR = playerCURR->next;
                }
                else{
                    playerCURR = getPlayerTeam();
                }
            }
            else{
                if(computerCURR->next != NULL){
                    computerCURR = computerCURR->next;
                }
                else{
                    computerCURR = getComputerTeam();
                }
            }
            break;
        case KEY_DOWN:
            fprintf(stderr,"Pressed down");
            if(turn == 0){
                if(playerCURR->next != NULL){
                    playerCURR = playerCURR->next;
                }
                else{
                    playerCURR = getPlayerTeam();
                }
            }
            else{
                if(computerCURR->next != NULL){
                    computerCURR = computerCURR->next;
                }
                else{
                    computerCURR = getComputerTeam();
                }
            }
            break;
        case KEY_LEFT:
            fprintf(stderr,"Pressed left");
            if(turn == 0){
                if(playerCURR->next != NULL){
                    playerCURR = playerCURR->next;
                }
                else{
                    playerCURR = getPlayerTeam();
                }
            }
            else{
                if(computerCURR->next != NULL){
                    computerCURR = computerCURR->next;
                }
                else{
                    computerCURR = getComputerTeam();
                }
            }
            break;
        case KEY_RIGHT:
            fprintf(stderr,"Pressed right");
            if(turn == 0){
                if(playerCURR->next != NULL){
                    playerCURR = playerCURR->next;
                }
                else{
                    playerCURR = getPlayerTeam();
                }
            }
            else{
                if(computerCURR->next != NULL){
                    computerCURR = computerCURR->next;
                }
                else{
                    computerCURR = getComputerTeam();
                }
            }
            break;
        case KEY_ENTER:
            fprintf(stderr,"Pressed Enter");
            if(turn == 0){
                if(playerCURR->next != NULL){
                    playerCURR = playerCURR->next;
                }
                else{
                    playerCURR = getPlayerTeam();
                }
            }
            else{
                if(computerCURR->next != NULL){
                    computerCURR = computerCURR->next;
                }
                else{
                    computerCURR = getComputerTeam();
                }
            }
            break;
    }

}

checkersPiece *findNextPiece(checkersPiece *currPiece, char direction){
    checkersPiece *nextPiece;
    double dist;
    if(turn == 1){
        checkersPiece *tempHead = computerCURR;
        switch(direction){
        
            case 'u':
                while(tempHead != NULL){
                    if(tempHead != currPiece && fabs(currPiece->yCoord - tempHead->yCoord) <= 1){
                        return nextPiece;
                    }  
                }
        
        }
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

void setDelay(int newDelay){
    delay = newDelay;
}

int getTurn(){
    return turn;
}
