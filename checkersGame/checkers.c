#include "checkers.h"

#define WHITE 0xFFFF
#define BLACK 0x0000
#define RED 0xF800
#define BLUE 0x1F
#define GREEN 0x7E0

/*

void display_team_1(pi_framebuffer_t *dev){
    sense_fb_bitmap_t *bm=dev->bitmap;
    
   //row 1
   bm->pixel[0][0] = RED;
   bm->pixel[2][0] = RED;
   bm->pixel[4][0] = RED;
   bm->pixel[6][0] = RED;

   // row 2
   bm->pixel[1][1] = RED;
   bm->pixel[3][1] = RED;
   bm->pixel[5][1] = RED;
   bm->pixel[7][1] = RED;
 
    // rot 3
   
   bm->pixel[0][2] = RED;
   bm->pixel[2][2] = RED;
   bm->pixel[4][2] = RED;
   bm->pixel[6][2] = RED;

}

void display_team_2(pi_framebuffer_t *dev){

    sense_fb_bitmap_t *bm=dev->bitmap;

    // row 1
    bm->pixel[1][7] = BLUE;
    bm->pixel[3][7] = BLUE;
    bm->pixel[5][7] = BLUE;
    bm->pixel[7][7] = BLUE;

    // row 2

    bm->pixel[0][6] = BLUE;
    bm->pixel[2][6] = BLUE;
    bm->pixel[4][6] = BLUE;
    bm->pixel[6][6] = BLUE;

    // row 3
    
    bm->pixel[1][5] = BLUE;
    bm->pixel[3][5] = BLUE;
    bm->pixel[5][5] = BLUE;
    bm->pixel[7][5] = BLUE;

}

*/

int main(){

    openDisplay();
    openJoystick();
    while(1){
        display_user_team();
        display_computer_team();
        checkJoystick();
    }

    //display_team_1(dev);
    //display_team_2(dev);

}
