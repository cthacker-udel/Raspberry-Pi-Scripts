#include "checkers.h"

int main(){

    openDisplay();
    openJoystick();
    display_user_team();
    display_computer_team();
    while(1){
        checkJoystick();
    }

    //display_team_1(dev);
    //display_team_2(dev);

}
