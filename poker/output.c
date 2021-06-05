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


pi_framebuffer_t *fb = NULL;

pokerCard *HEAD = NULL;

pokerCard *createCard(char suit, int rank){
    
}


void constructDeck(){



}



void openDisplay(void){

    if(!fb){
        fb = getFrameBuffer();
    }
    else{
        fprintf(stderr,"Unable to intialize a framebuffer that has already been initialized");
    }

}


void closeDisplay(void){

   if(fb){
        clearFrameBuffer(fb,BLACK);
        freeFrameBuffer(fb);
        fb = NULL;
   }
   else{
        fprintf(stderr,"Attempting to close a framebuffer that has not been initialized or otherwise already closed");
   }

}


void clearDisplay(void){

   if(!fb){
        fprintf(stderr,"Attemping to clear the framebuffer when it has not been initialized");
   }
   else{
        clearFrameBuffer(fb,BLACK);
   }

}

