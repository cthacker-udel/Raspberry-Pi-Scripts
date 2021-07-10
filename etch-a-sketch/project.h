/*
 *
 * @author - Cameron Thacker
 *
 */


#include <signal.h>
#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

// ###################
// # OUTPUT.C METHODS
// ###################

// Framebuffer

void openDisplay(void);

void closeDisplay(void);

void displayColor(int,int,int);

void clearDisplay(void);

// ##################
// # INPUT.C METHODS
// ##################

// Joystick

void handler(unsigned int);

void openJoystick(void);

void closeJoystick(void);

void checkJoystick(void);

int getXPos(void);

int getYPos(void);

unsigned int getJsCode(void);

int getCurrColor(void);

void setDelay(int);

int getFirst(void);

void setFirst(int);

// Accelerometer

void openAccel(void);

void closeAccel(void);

void checkAccel(void);

void resetAccelData(void);

float accelX(void);

float accelY(void);

float accelZ(void);

void setShake(int);

int getShake(void);
