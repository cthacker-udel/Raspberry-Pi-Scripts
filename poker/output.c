#include "project.h"


pi_framebuffer_t *fb = NULL;

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
    fb = NULL;
    freeFrameBuffer(fb);
   }
   else{
    fprintf(stderr,"Attempting to close a framebuffer that has not been initialized or otherwise already closed");
   }

}

