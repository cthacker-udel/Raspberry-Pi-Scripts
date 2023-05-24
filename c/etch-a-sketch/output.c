/*
 *
 * @author - Cameron Thacker
 *
 */


#include "project.h"

#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0x1F
#define RED 0xF800
#define YELLOW 0xFFE0
#define ORANGE 0xFBE0
#define BROWN 0x79E0
#define GREEN 0x7E0
#define CYAN 0x7FF

// #############
// # PROTOTYPES
// #############

/*
 *
 * Prototype - openDisplay - intializes framebuffer object
 *
 */

void openDisplay(void);

// ######################
// # FRAMEBUFFER METHODS
// ######################


/*
 *
 * fb - Framebuffer object, global variable initialized to NULL
 *
 */

pi_framebuffer_t *fb = NULL;

/*
 * parameter - void
 * return - void
 *
 * Opens Display, initialized Framebuffer object to Framebuffer
 *
 *
 */

void openDisplay(void){
    if(fb == NULL){
        fb = getFrameBuffer();
    }
}

/*
 *
 * parameter - void
 * return - void
 *
 * Closes Display, clears Framebuffer and deallocates Framebuffer Object, setting the Framebuffer object back to NULL
 *
 */

void closeDisplay(void){

    if(fb == NULL){
        fprintf(stderr,"Attempting to close a framebuffer that has not been allocated");
        return;
    }
    else{
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        fb = NULL;
    }
}

/*
 *
 * parameter - void
 * return - void
 *
 * Clears Framebuffer 
 *
 */

void clearDisplay(void){
    clearFrameBuffer(fb,BLACK);
}

/*
 *
 * paramater - int, int, int
 * return - void
 *
 * color - color to display, numerically determined and switch statement chooses which color to display
 * xPos - x position of pixel
 * yPos - y position of pixel
 *
 * Displays color according to color given, x position to display the pixel, and y position to display the pixel
 *
 */

void displayColor(int color, int xPos, int yPos){

    sense_fb_bitmap_t *bm=fb->bitmap;

    switch(color){
    
        case 0:
            bm->pixel[yPos][xPos] = BLACK;
            break;
        case 1:
            bm->pixel[yPos][xPos] = WHITE;
            break;
        case 2:
            bm->pixel[yPos][xPos] = BLUE;
            break;
        case 3:
            bm->pixel[yPos][xPos] = RED;
            break;
        case 4:
            bm->pixel[yPos][xPos] = YELLOW;
            break;
        case 5:
            bm->pixel[yPos][xPos] = ORANGE;
            break;
        case 6:
            bm->pixel[yPos][xPos] = BROWN;
            break;
        case 7:
            bm->pixel[yPos][xPos] = GREEN;
            break;
        case 8:
            bm->pixel[yPos][xPos] = CYAN;
            break;
        default:
            break;
    
    }

}

