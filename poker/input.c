#include "project.h"

pi_joystick_t *joystick = NULL;


pi_i2c_t *accelerometer = NULL;

int delay = 1000;


/*
 *
 * Open Joystick
 *
 */


void openJoystick(void){

    if(joystick){
        fprintf(stderr,"Attempting to initialize a joystick that has already been initialized");
    }
    else{
        joystick = getJoystickDevice();
    }

}

void closeJoystick(void){

    if(!joystick){
        fprintf(stderr,"Attempting to close a joystick device that has already been closed");
    }
    else{
        freeJoystick(joystick);
        joystick = NULL;
    }

}

void handler(unsigned int code){
    switch(code){
        case KEY_UP:
            fprintf(stderr,"\nKEY PRESSED : UP\n");
            break;
        case KEY_DOWN:
            fprintf(stderr,"\nKEY PRESSED : DOWN\n");
            break;
        case KEY_RIGHT:
            fprintf(stderr,"\nKEY PRESSED : RIGHT\n");
            break;
        case KEY_LEFT:
            fprintf(stderr,"\nKEY PRESSED : LEFT\n");
            break;
        case KEY_ENTER:
            fprintf(stderr,"\nKEY PRESSED : ENTER\n");
            break;
        default:
            fprintf(stderr,"\nDEFAULT CASE REACHED\n");
            break;
    }
}



void checkJoystick(void){
    pollJoystick(joystick,handler,delay);
}
