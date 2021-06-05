#include "project.h"



int main(void){
    openDisplay();
    openJoystick();
    while(1){
        checkJoystick();
    }
}
