/*
 *
 * @author - Cameron Thacker
 *
 */


#include "project.h"


// #############
// # PROTOTYPES
// #############

/*
 *
 * Prototype - openJoystick method - initializing the joystick
 *
 */

void openJoystick(void);

/*
 *
 * Prototype - openAccel method - initializing the accelerometer
 *
 */

void openAccel(void);

// ###################
// # JOYSTICK METHODS
// ###################


/*
 *
 * joystick - joystick device, initialized to NULL since global variable
 *
 */

pi_joystick_t *joystick = NULL;

/*
 *
 * accelerometer - accelerometer device, initialized to NULL since global variable
 *
 */

pi_i2c_t *accelerometer = NULL;

/*
 *
 * xPos - current x pixel position
 * yPos - current y pixel position
 *
 */

int xPos = 0, yPos = 0;

/*
 * jsCode - used to track joystick code
 *
 */

unsigned int jsCode = 0;

/*
 *
 * currColor - current color being displayed, code functioning with this variable provided in output.c
 *
 */

int currColor = 1;

/*
 *
 * x - acceleration in x 
 * y - acceleration in y
 * z - acceleration in z
 *
 */

float x=0,y=0,z=0;

/*
 *
 * data - accelerometer data , structure type, instance variables x,y,z, stores acceleration data
 *
 */

coordinate_t data;

/*
 *
 * delay - checkJoystick delay, the time frame joystick inputs are recorded, measured in milliseconds
 *
 */

int delay = 100;


/*
 *
 * isShake - boolean value to indicate whether a shake was made
 *
 */

int isShake = 0;

/*
 *
 * firstMove - integer value that makes sure no colors are displayed until first move
 *
 */

int firstMove = 0;

// ########################
// # ACCELEROMETER METHODS
// ########################

/*
 * parameter - void
 * return - void
 *
 * Opening accelerometer
 *
 */
void openAccel(void){
    if(accelerometer == NULL){
        accelerometer = geti2cDevice();
        configureAccelGyro(accelerometer);
    }
}

/*
 * parameter - void
 * return - void
 *
 * Closing accelerometer
 *
 */
void closeAccel(void){
    if(accelerometer == NULL){
        fprintf(stderr,"Attempting to close a accelerometer that is already closed");
        return;
    }
    else{
        freei2cDevice(accelerometer);
    }
}

/*
 * parameter - void
 * return - void
 *
 * Checking accelerometer for data
 *
 */
void checkAccel(void){
    
    getAccelData(accelerometer,&data);
    x += data.x;
    y += data.y;
    z += data.z;

    /*
     * Displays average velocity
     *
     *
     *   if(cnt == delay){
     *       fprintf(stderr,"Average velocity = %f %f %f \n",x / delay, y / delay, z / delay);
     *       x = 0, y = 0, z = 0, cnt = 0;
     *   } 
     */

    //fprintf(stderr,"\n----------\nx = [%f]\n",x); <-- prints accelerometer x coordinate data
    //fprintf(stderr,"\ny = [%f]\n",y); <-- prints accelerometer y coordinate data
    //fprintf(stderr,"\nz = [%f]\n---------\n",z); <-- prints accelerometer z coordinate data
    
}

/*
 *
 * parameter - void
 * return - void
 *
 * Resets accelerometer x coordinate data, y coordinate data, and z coordinate data
 *
 *
 */

void resetAccelData(void){
    x = 0;
    y = 0;
    z = 0;
}

/*
 * parameter - void
 * return float - acceleration in x direction
 *
 * Get Accelerometer X
 *
 */

float accelX(void){
    return x;
}

/*
 * parameter - void
 * return float - acceleration in y direction
 *
 * Get Accelerometer Y
 *
 */

float accelY(void){
    return y; 
}

/*
 * parameter - void
 * return float - acceleration in z direction
 *
 * Get Accelerometer Z
 *
 */

float accelZ(void){
    return z;
}

/*
 *
 * parameter - int
 * return - void
 *
 * Sets the isShake value to the parameter passed in
 *
 */

void setShake(int isShook){
    isShake = isShook;
}

/*
 *
 * parameter - void
 * return - int
 *
 * Returns if the Pi has been shaken
 *
 */

int getShake(void){
    return isShake;
}

// ###################
// # JOYSTICK METHODS
// ###################


/*
 * parameter - unsigned int - represents the joystick code, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, or KEY_ENTER, corresponding to pressing the joystick in each direction
 * return - void
 *
 * Joystick callback function
 *
 */

void handler(unsigned int code){

    //fprintf(stderr,"\nThe code = %d\n",code); //<-- prints code given
    
    if(isShake){
        setShake(0);
    }
    if(!firstMove){
        firstMove = 1;
    }

    jsCode = code;

    switch(code){
    
        case KEY_UP:

            //fprintf(stderr,"\nup\n"); <-- prints direction pressed

            if(yPos == 0){
                yPos = 7;
            }
            else{
                yPos--;
            }
            break;
        
        case KEY_DOWN:

            //fprintf(stderr,"\ndown\n"); <-- prints direction pressed
            
            if(yPos == 7){
                yPos = 0;
            }
            else{
                yPos++;
            }
            break;

        case KEY_LEFT:

            //fprintf(stderr,"\nleft\n"); <-- prints direction pressed

            if(xPos == 0){
                xPos = 7;
            }
            else{
                xPos--;
            }
            break;

        case KEY_RIGHT:

            //fprintf(stderr,"\nright\n"); <-- prints direction pressed

            if(xPos == 7){
                xPos = 0;
            }
            else{
                xPos++;
            }
            break;

        case KEY_ENTER:

            if(currColor < 8){
                if(currColor == 0){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","WHITE");
                }
                else if(currColor == 1){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","BLUE");
                }
                else if(currColor == 2){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","RED");
                }
                else if(currColor == 3){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","YELLOW");
                }
                else if(currColor == 4){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","ORANGE");
                }
                else if(currColor == 5){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","BROWN");
                }
                else if(currColor == 6){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","GREEN");
                }
                else if(currColor == 7){
                    fprintf(stderr,"\n################\n# COLOR : %s\n################\n","CYAN");
                }
                currColor++;
            }
            else{
                fprintf(stderr,"\n################\n# COLOR : %s\n################\n","BLACK");
                currColor = 0;
            }

            break;

        default:
            break;
    }

}


/*
 *
 * parameter - void
 * return - int
 *
 * Get current color integer representation
 *
 */

int getCurrColor(void){
    return currColor;
}

/*
 * parameter - void
 * return unsigned int - joystick code, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, or KEY_ENTER corresponding to pressing the joystick in each direction
 *
 * Get Code Given to Joystick Callback
 *
 */

unsigned int getJsCode(void){
    return jsCode;
}

/*
 * parameter - void
 * return - int - pixel x position
 *
 * Get X Position
 *
 */

int getXPos(void){
    return xPos;
}

/*
 * parameter - void
 * return - int - pixel y position
 *
 * Get Y Position
 *
 */

int getYPos(void){
    return yPos;
}

/*
 * parameter - void
 * return - void 
 *
 * Assigning NULL joystick to joystick device, initializing the joystick device with a value
 *
 * Opening joystick
 *
 */
void openJoystick(void){

    if(joystick == NULL){
        joystick = getJoystickDevice();
    }

}

/*
 * parameter - void
 * return - void
 *
 * Closing joystick
 *
 */

void closeJoystick(void){

    if(joystick == NULL){
        fprintf(stderr,"Attempting to close a joystick that has not been allocated");
        return;
    }
    else{
        freeJoystick(joystick);
    }

}

/*
 * parameter - void
 * return - void
 *
 * Checking joystick for input
 *
 */

void checkJoystick(void){
    pollJoystick(joystick,handler,delay);
}

/*
 *
 * parameter - int
 * return - void
 *
 * Sets checkJoystick delay to int passed into function
 *
 */

void setDelay(int newDelay){
    delay = newDelay;
}

/*
 *
 * parameter - int
 * return - void
 *
 * Sets First Move to integer given
 *
 */

void setFirst(int newFirst){
    firstMove = newFirst;
}


/*
 *
 * parameter - void
 * return - int
 *
 * Gets firstMove variable
 *
 */

int getFirst(void){
    return firstMove;
}
