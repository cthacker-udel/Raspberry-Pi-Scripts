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
        display_created_user_team();
        display_created_computer_team();
        if(getTurn() == 1){
            currCursor(getComputerCURR());
        }
        else{
            currCursor(getPlayerCURR());
        }
    }

}
