#include "project.h"

pi_joystick_t *joystick = NULL;


pi_i2c_t *accelerometer = NULL;


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
