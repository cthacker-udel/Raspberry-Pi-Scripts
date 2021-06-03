#include "checkers.h"

#define RED 0xF800
#define BLUE 0x1F
#define BLACK 0x0000
#define YELLOW 0xFFE0
#define ORANGE 0xFBE0
#define BROWN 0x79E0
#define GREEN 0x7E0
#define CYAN 0x7FF

pi_joystick_t *joystick = NULL;

int delay = 100;

int xCoord;

int yCoord;

int prevX;

int prevY;

int turn;

int chooseMove = 0;

int prevColor = 0;

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
    computerCURR = getComputerTeam();
    playerCURR = getPlayerTeam();
    if(turn == 1){
        currCursor(computerCURR);
    }
    else{
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

    fprintf(stderr,"\n%@%@%@%\nENTERING HANDLER\n%@%@%@%\n");

    switch(code){
        case KEY_UP:
            fprintf(stderr,"\n}U}U}U\nPressed up\n}U}U}U\n");
            if(chooseMove && xCoord >= 0){
                if(xCoord == 0){
                    xCoord = 7;
                }
                else{
                    xCoord--;
                }


                if(prevColor == 31){
                    displayChooseMove(prevX,prevY,'b');
                }
                else if(prevColor == 63488){
                    displayChooseMove(prevX,prevY,'r');
                }
                else{
                    displayChooseMove(prevX,prevY,'z');
                }

                int currColor = getColorVal(xCoord,yCoord); 
                
                if(currColor == 0){
                    displayChooseMove(xCoord,yCoord,'g');
                }
                else if(currColor == 31){
                    displayChooseMove(xCoord,yCoord,'b');
                }
                else if(currColor == 63488){
                    displayChooseMove(xCoord,yCoord,'r');
                }
                prevColor = currColor;
                prevY = yCoord;
                prevX = xCoord;
                printf("\n################\nGreen cursor coords : %d,%d\n###################\n",xCoord,yCoord); 
            }
            else if(turn == 0){ // computer's turn
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
            fprintf(stderr,"\n$D$D$D\nPressed down\n$D$D$D\n");
            if(chooseMove && xCoord <= 7){
                if(xCoord == 7){
                    xCoord = 0;
                }
                else{
                    xCoord++;
                }
                if(prevColor == 31){
                    displayChooseMove(prevX,prevY,'b');
                }
                else if(prevColor == 63488){
                    displayChooseMove(prevX,prevY,'r');
                }
                else{
                    displayChooseMove(prevX,prevY,'z');
                }

                int currColor = getColorVal(xCoord,yCoord);

                if(currColor == 0){
                    displayChooseMove(xCoord,yCoord,'g');
                }
                else if(currColor == 31){
                    displayChooseMove(xCoord,yCoord,'b');
                }
                else if(currColor == 63488){
                    displayChooseMove(xCoord,yCoord,'r');
                }
                prevColor = currColor;
                prevY = yCoord;
                prevX = xCoord;
                printf("\n################\nGreen cursor coords : %d,%d\n###################\n",xCoord,yCoord); 
            }
            else if(turn == 0){
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
            fprintf(stderr,"\n@L@L@L\nPressed left\n@L@L@L\n");
            if(chooseMove && yCoord >= 0){
                if(yCoord == 0){
                    yCoord = 7;
                }
                else{
                    yCoord--;
                }
                if(prevColor == 31){
                    displayChooseMove(prevX,prevY,'b');
                }
                else if(prevColor == 63488){
                    displayChooseMove(prevX,prevY,'r');
                }
                else{
                    displayChooseMove(prevX,prevY,'z');
                }

                int currColor = getColorVal(xCoord,yCoord);

                if(currColor == 0){
                    displayChooseMove(xCoord,yCoord,'g');
                }
                else if(currColor == 31){
                    displayChooseMove(xCoord,yCoord,'b');
                }
                else if(currColor == 63488){
                    displayChooseMove(xCoord,yCoord,'r');
                }

                prevColor = currColor;
                prevY = yCoord;
                prevX = xCoord;
                printf("\n################\nGreen cursor coords : %d,%d\n###################\n",xCoord,yCoord); 
            }
            else if(turn == 0){
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
            fprintf(stderr,"\n^R^R^R\nPressed right\n^R^R^R\n");
            if(chooseMove && yCoord <= 7){
                if(yCoord == 7){
                    yCoord = 0;
                }
                else{
                    yCoord++;
                }
                if(prevColor == 31){
                    displayChooseMove(prevX,prevY,'b');
                }
                else if(prevColor == 63488){
                    displayChooseMove(prevX,prevY,'r');
                }
                else{
                    displayChooseMove(prevX,prevY,'z');
                }

                int currColor = getColorVal(xCoord,yCoord);

                if(currColor == 0){
                    displayChooseMove(xCoord,yCoord,'g');
                }
                else if(currColor == 31){
                    displayChooseMove(xCoord,yCoord,'b');
                }
                else if(currColor == 63488){
                    displayChooseMove(xCoord,yCoord,'r');
                }

                prevColor = currColor;
                prevY = yCoord;
                prevX = xCoord;
                printf("\n################\nGreen cursor coords : %d,%d\n###################\n",xCoord,yCoord);
            }
            else if(turn == 0){
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
            fprintf(stderr,"\n!=!=!=\nPressed Enter\n!=!=!=\n");
            if(turn == 0){
                printf("\n Entering turn 0 if statement\n");
                if(chooseMove == 1){ // move selected
                    printf("\nEntering choosemove turn 0 if statement");
                    if(validMove(playerCURR,xCoord,yCoord)){
                        setTurn(1);
                        chooseMove = 0;
                    }
                }
                else{
                    chooseMove = 1;
                    xCoord = playerCURR->xCoord;
                    yCoord = playerCURR->yCoord;
                }
            }
            else{
                if(chooseMove == 1){
                    if(validMove(computerCURR,xCoord,yCoord)){
                        setTurn(0);
                        chooseMove = 0;
                    }
                }
                else{
                    chooseMove = 1;
                    xCoord = computerCURR->xCoord;
                    yCoord = computerCURR->yCoord;
                    prevX = xCoord;
                    prevY = yCoord;
                }
            }
            break;
    }

}

/*
 *
 *computer choosing attack : make binary search tree and collect points for each move, (take one or two enemy pieces --> 4 points example), then make the computer traverse the tree, and the best node, execute the move
 *
 */

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

int validMove(checkersPiece *currPiece, int x2, int y2){

    fprintf(stderr,"\n\n ENTERING VALID MODE \n\n");

    pi_framebuffer_t *fb = getDisplay();
   
    sense_fb_bitmap_t *bm = fb->bitmap; 

    fprintf(stderr,"\n\n Reached else \nStats : \nCURR(x,y) = (%d,%d)\nGREEN(x,y) = (%d,%d)\nCURRCOLOR = %d\n\n",currPiece->xCoord,currPiece->yCoord,x2,y2,getColorVal(x2,y2));

    if(currPiece->xCoord == 7 && x2 == 0){
        fprintf(stderr,"\n\n --------------- INVALID MOVE ---------------- \n\n");
        return 0;
    }
    else if(currPiece->yCoord == 7 && y2 == 0){
        fprintf(stderr,"\n\n ------------------- INVALID MOVE ----------------- \n\n");
        return 0;
    }
    else{
        if(turn == 0){
            if(bm->pixel[x2][y2] == RED){
                fprintf(stderr,"\n\n --------------------- INVALID MOVE ------------------------ \n\n");
                return 0;
            }
            else{
                // just update move, add functionality if opposing player is in space
                if(fabs(x2 - currPiece->xCoord) == 1 && fabs(y2 - currPiece->yCoord) == 1 && getColorVal(x2,y2) == 2016){
                    fprintf(stderr,"\n\n------ VALID MOVE -------(1 - user) - Standard Move\n\n");
                    bm->pixel[currPiece->xCoord][currPiece->yCoord] = BLACK;
                    currPiece->xCoord = x2;
                    currPiece->yCoord = y2;
                    return 1;
                }
                else if(fabs(x2 - currPiece->xCoord) == 2 && fabs(y2 - currPiece->yCoord) == 2 && getColorVal(x2,y2) == 2016){
                    if(x2 > currPiece->xCoord){
                        if(getColorVal(x2+1,y2-1) == 31 || getColorVal(x2+1,y2+1) == 31){
                            fprintf(stderr,"\n\n--------- VALID MOVE -----------(2 - user) - ATTACK!(left to right)\n\n");
                            return 1;
                        }
                        else{
                            fprintf(stderr,"\n\n ------------- INVALID MOVE --------------- \n\n");
                            return 0;
                        }
                    }
                    else if(x2 < currPiece->xCoord){
                        if(getColorVal(x2+1,y2-1) == 31 || getColorVal(x2+1,y2+1) == 31){
                            fprintf(stderr,"\n\n ---------------- VALID MOVE ---------------- (3 - user) - Attack(Right to left)\n\n");
                            if(getColorVal(x2+1,y2-1) == 31){
                                bm->pixel[x2+1][y2-1] = BLACK;
                                bm->pixel[x2][y2] = RED;
                                bm->pixel[currPiece->xCoord][currPiece->yCoord] = BLACK;
                                currPiece->xCoord = x2;
                                currPiece->yCoord = y2;
                                removeComputerPiece(x2+1,y2-1);
                                computerCURR = getComputerTeam();
                                return 1;
                            }
                            else{
                                bm->pixel[x2+1][y2+1] = BLACK;
                                bm->pixel[x2][y2] = RED;
                                bm->pixel[currPiece->xCoord][currPiece->yCoord] = BLACK;
                                currPiece->xCoord = x2;
                                currPiece->yCoord = y2;
                                removeComputerPiece(x2+1,y2+1);
                                computerCURR = getComputerTeam();
                                return 1;
                            }

                            return 1;
                        }
                        else{
                            fprintf(stderr,"\n\n --------------- INVALID MOVE ---------------- \n\n");
                            return 0;
                        }
                    
                    }
                }
                else{
                    fprintf(stderr,"\n\n Reached else \nStats : \nCURR(x,y) = (%d,%d)\nGREEN(x,y) = (%d,%d)\nCURRCOLOR = %d\n\n",currPiece->xCoord,currPiece->yCoord,x2,y2,getColorVal(x2,y2));
                    return 0;
                }
                //bm->pixel[xCoord][yCoord] = RED;
                //bm->pixel[currPiece->xCoord][currPiece->yCoord] = BLACK;
                //turn = 1;
                //currPiece->xCoord = xCoord;
                //currPiece->yCoord = yCoord;
            }
        }
        else{
            if(bm->pixel[x2][y2] == BLUE){
                fprintf(stderr,"\n\n -------------------- INVALID MOVE ----------------------- \n\n");
                return 0;
            }
            else{
                if(fabs(x2 - currPiece->xCoord) == 1 && fabs(y2 - currPiece->yCoord) == 1 && getColorVal(x2,y2) == 2016){
                    fprintf(stderr,"\n\n ------------ VALID MOVE ------------- \n\n");
                    bm->pixel[currPiece->xCoord][currPiece->yCoord] = BLACK;
                    currPiece->xCoord = x2;
                    currPiece->yCoord = y2;
                    return 1;
                }
                else if(fabs(x2 - currPiece->xCoord) == 2 && fabs(y2 - currPiece->yCoord) == 2 && getColorVal(x2,y2) == 2016){
                    if(x2 > currPiece->xCoord){
                        if(getColorVal(x2-1,y2-1) == 63488 || getColorVal(x2-1,y2+1) == 63488){
                            fprintf(stderr,"\n\n ---------- VALID MOVE ------------- \n\n");
                            return 1;
                        }
                        else{
                            fprintf(stderr,"\n\n ----------- INVALID MOVE -------------- \n\n");
                            return 0;
                        }
                    }
                    else if(x2 < currPiece->xCoord){
                        if(getColorVal(x2+1,y2-1) == 63488 || getColorVal(x2+1,y2+1) == 63488){
                            fprintf(stderr,"\n\n -------------- VALID MOVE --------------- \n\n");
                            return 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else{
                    fprintf(stderr,"\n\n Reached else \nStats : \nCURR(x,y) = (%d,%d)\nGREEN(x,y) = (%d,%d)\nCURRCOLOR = %d\n\n",currPiece->xCoord,currPiece->yCoord,x2,y2,getColorVal(x2,y2));
                    return 0;
                }

            }
        }
    }

}


int getChooseMove(){
    return chooseMove;
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

void setTurn(int newTurn){
    turn = newTurn;
}

int getXCoord(){
    return xCoord;
}

int getYCoord(){
    return yCoord;
}
