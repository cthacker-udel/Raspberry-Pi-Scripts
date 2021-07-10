/*
 *
 * @author - Cameron Thacker
 *
 */


#include "project.h"


/*
 *
 * parameter - void
 * return - int
 *
 * Begins by allocating the Framebuffer, clearing the display if previously ran and pixels still displayed, and then allocates the Joystick, and Accelerometer, and then prints the initial color to the console, White, and then
 * runs checkJoystick, checking for user input, whether changing colors or moving the current position of the pixel displaying, then checks the accelerometer coordinate data using a combination of checkAccel, accelX, accelY, 
 * accelZ, and fabs, to see if there are any significant differences among the coordinate data previously, if there is significant change, then that means that the Pi was moved substantially, meaning the Pi was shook, 
 * when the Pi is shook, the display is cleared and all pixels are erased, if the pi is not shaken, then the display is not erased. If the if statement is not trigged, then the variables accX, accY, and accZ are updated to the
 * current accelerometer coordinate data, and then the coordinate data is reset to 0. After the function is done running, the display is closed, joystick is closed, and accelerometer is closed as well.
 *
 * ----------------------
 * --- Variables used ---
 * ----------------------
 *
 * float accX - accelerometer coordinate x data
 * float accY - accelerometer coordinate y data
 * float accZ - accelerometer coordinate z data
 *
 * --------------------
 * --- Methods used ---
 * --------------------
 *
 *  ###########
 *  # OUTPUT.C
 *  ###########
 *
 *  openDisplay() - allocates Framebuffer object
 *
 *  clearDisplay() - clears Framebuffer object
 *
 *  ##########
 *  # INPUT.C
 *  ##########
 *
 *  openJoystick() - allocates Joystick object
 *
 *  openAccel() - allocates Accelerometer object
 *  
 *  checkJoystick() - Checking joystick for input
 *
 *  checkAccel() - Checking accelerometer for coordinate data
 *
 *  closeDisplay() - deallocates Framebuffer object
 *
 *  closeJoystick() - deallocated Joystick object
 *
 *  closeAccel() - deallocates Accelerometer object
 *
 *  accelX() - gets accelerometer x coordinate data
 *
 *  accelY() - gets accelerometer y coordinate data
 *
 *  accelZ() - gets accelerometer z coordinate data
 *
 *  resetAccelData() - resets all accelerometer coordinate data to 0
 *
 *  #########
 *  # MATH.H
 *  #########
 *
 *  fabs(double val) - calculates absolute value of double value passed
 *
 */

int main(void){
   
    float accX = 0;
    float accY = 0;
    float accZ = 0;

    openDisplay();
    clearDisplay();
    openJoystick();
    openAccel();
    fprintf(stderr,"################\n# COLOR : %s\n################\n","WHITE");
    setDelay(100);
    while(1){
        checkJoystick();
        if(!getShake() && getFirst()){
            displayColor(getCurrColor(),getXPos(),getYPos());
        }
        checkAccel();
        if(accX != 0 || accY != 0 || accZ != 0){
            if(fabs(accX - accelX()) >= .90 || fabs(accY - accelY()) >= .90 || fabs(accZ - accelZ()) >= .90){
                clearDisplay();
                setShake(1);
            }
        }
        accX = accelX();
        accY = accelY();
        accZ = accelZ();
        resetAccelData();
    }

    closeDisplay();
    closeJoystick();
    closeAccel();
    return 0;
}
