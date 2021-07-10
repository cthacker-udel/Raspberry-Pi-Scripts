/*
 *
 * @author - Cameron Thacker
 *
 */

#include "project.h"

/*
 *
 * First tests the joystick input, and then once user presses enter, tests the accelerometer input
 *
 * Joystick Test - consists of printing the x and y positions of the pixel as the user is giving input to the joystick
 *
 * Accelerometer Test - consists of printing the average acceleration while the user physically moves the Pi device
 *
 * --------------------
 * --- Methods used ---
 * --------------------
 *
 * ###########
 * # JOYSTICK
 * ###########
 *
 * openJoystick() - allocates Joystick device
 *
 * checkJoystick() - checks for user joystick input
 *
 * getXPos() - gets pixel x position
 *
 * getYPos() - gets pixel y position
 *
 * getJsCode() - gets user joystick input represented as unsigned int, used to exit loop to begin accelerometer testing
 *
 * closeJoystick() - deallocated joystick device
 *
 * setDelay(int) - Set checkJoystick delay time
 *
 * ################
 * # ACCELEROMETER
 * ################
 *
 * openAccel() - allocates accelerometer device
 *
 * checkAccel() - checks accelerometer for coordinate data, prints average acceleration
 *
 * accelX() - gets accelerometer x coordinate data
 *
 * accelY() - gets accelerometer y coordinate data
 *
 * accelZ() - gets accelerometer z coordinate data
 *
 * resetAccelData() - resets all accelerometer coordinate data variables to 0
 *
 * closeAccel() - deallocated accelerometer device 
 *
 */


int main(void){
    fprintf(stderr,"\nMOVE TO COORDINATE 4,4 TO SWITCH TO ACCELEROMETER INPUT TEST\n");

    openJoystick();
    openAccel();
    setDelay(1000);

    /*
     *
     * Joystick check
     *
     */
    
    for(;;){
        checkJoystick();
        int x = getXPos();
        int y = getYPos();
        unsigned int code = getJsCode();
        fprintf(stderr,"\n\nreceived signal from joystick : xPos = %d and yPos = %d\n",x,y);
        if(x == 4 && y == 4){
            break;
        }
    }
    closeJoystick();

    /*
     *
     * Accelerometer check
     *
     */
    
    fprintf(stderr,"\n\nTesting accelerometer code\n\n");
    sleep(1);
    while(1){
        checkAccel();
        float x = accelX();
        float y = accelY();
        float z = accelZ();
        fprintf(stderr,"\nreceived signal from accelerometer : x : %f y : %f z : %f\n\n",x,y,z);
        resetAccelData();
        usleep(95000);
    }
    closeAccel();
}
