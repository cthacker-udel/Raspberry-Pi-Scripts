
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

/*
 *
 * Display teams
 *
 */ 

void display_user_team(){
    if(fb == NULL){
        openDisplay();
    }
    else{
        sense_fb_bitmap_t *bm = fb->bitmap;

        bm->pixel[0][0] = RED;
        bm->pixel[2][0] = RED;
        bm->pixel[4][0] = RED;
        bm->pixel[6][0] = RED;

        bm->pixel[1][1] = RED;
        bm->pixel[3][1] = RED;
        bm->pixel[5][1] = RED;
        bm->pixel[7][1] = RED;

        bm->pixel[0][2] = RED;
        bm->pixel[2][2] = RED;
        bm->pixel[4][2] = RED;
        bm->pixel[6][2] = RED;
    }
}


void display_computer_team(){

    if(fb == NULL){
        openDisplay();
    }
    else{
        sense_fb_bitmap_t *bm = fb->bitmap;

        bm->pixel[1][7] = BLUE;
        bm->pixel[3][7] = BLUE;
        bm->pixel[5][7] = BLUE;
        bm->pixel[7][7] = BLUE;

        bm->pixel[0][6] = BLUE;
        bm->pixel[2][6] = BLUE;
        bm->pixel[4][6] = BLUE;
        bm->pixel[6][6] = BLUE;

        bm->pixel[1][5] = BLUE;
        bm->pixel[3][5] = BLUE;
        bm->pixel[5][5] = BLUE;
        bm->pixel[7][5] = BLUE;
    }

}



