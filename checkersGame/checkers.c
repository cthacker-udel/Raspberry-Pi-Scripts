#include "checkers.h"

int main(){

    openDisplay();
    openJoystick();
    while(1){
        display_user_team();
        display_computer_team();
        checkJoystick();
    }

    //display_team_1(dev);
    //display_team_2(dev);

}
