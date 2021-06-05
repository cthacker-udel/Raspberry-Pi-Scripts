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
