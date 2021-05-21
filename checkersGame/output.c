
/**
 *
 * Colors
 *
 */

#include "checkers.h"

#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0x1F
#define RED 0xF800
#define YELLOW 0xFFE0
#define ORANGE 0xFBE0
#define BROWN 0x79E0
#define GREEN 0x7E0
#define CYAN 0X7FF


pi_framebuffer_t *fb = NULL;


void openDisplay(void){
    if(fb == NULL){
        fb = getFrameBuffer();
    }
}


void closeDisplay(void){
    if(fb){
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        fb = NULL;
    }
}

void clearDisplay(void){
    clearFrameBuffer(fb,BLACK);
}



