#include "checkers.h"

int main(){

    openDisplay();
    openJoystick();
    clearDisplay();
    fprintf(stderr,"\n\nDisplaying the user team\n");
    display_user_team();
    fprintf(stderr,"\n\nDisplaying the computer team\n");
    display_computer_team();
    fprintf(stderr,"\n\n");
    coinFlip();
    while(1){
        checkJoystick();
        if(getTurn() == 1){
            currCursor(getComputerCURR());
        }
        else{
            currCursor(getPlayerCURR());
        }
    }

}
