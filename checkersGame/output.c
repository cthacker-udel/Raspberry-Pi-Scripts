
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

checkersPiece *PLAYERHEAD = NULL;

checkersPiece *COMPUTERHEAD = NULL;


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

checkersPiece *craftPiece(int x, int y){

    checkersPiece *newPiece = (checkersPiece *)malloc(sizeof(checkersPiece));
    newPiece->next = NULL;
    newPiece->xCoord = x;
    newPiece->yCoord = y;
    newPiece->isKing = 0;
    return newPiece;

}

void showTeam(checkersPiece *TEAM){

    checkersPiece *tempHead = TEAM;
    int number = 1;
    while(tempHead){
        printf("Piece # %d | (%d,%d)\n",number++,tempHead->xCoord,tempHead->yCoord);
        tempHead = tempHead->next;
    }

}


void display_user_team(){
    if(fb == NULL){
        openDisplay();
    }
    else{
        sense_fb_bitmap_t *bm = fb->bitmap;
        
        checkersPiece *newPiece;

        if(PLAYERHEAD == NULL){
            PLAYERHEAD = craftPiece(0,0);
        }

        bm->pixel[0][0] = RED;

        newPiece = craftPiece(2,0);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[2][0] = RED;
    
        newPiece = craftPiece(4,0);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[4][0] = RED;

        newPiece = craftPiece(6,0);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[6][0] = RED;

        newPiece = craftPiece(1,1);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[1][1] = RED;

        newPiece = craftPiece(3,1);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[3][1] = RED;

        newPiece = craftPiece(5,1);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[5][1] = RED;

        newPiece = craftPiece(7,1);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[7][1] = RED;
        
        newPiece = craftPiece(0,2);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[0][2] = RED;

        newPiece = craftPiece(2,2);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[2][2] = RED;

        newPiece = craftPiece(4,2);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[4][2] = RED;
    
        newPiece = craftPiece(6,2);
        newPiece->next = PLAYERHEAD;
        PLAYERHEAD = newPiece;

        bm->pixel[6][2] = RED;

        showTeam(PLAYERHEAD);
    }
}


void display_computer_team(){

    if(fb == NULL){
        openDisplay();
    }
    else{
        sense_fb_bitmap_t *bm = fb->bitmap;

        checkersPiece *newPiece;

        if(COMPUTERHEAD == NULL){
            COMPUTERHEAD = craftPiece(1,7);
        }

        bm->pixel[1][7] = BLUE;

        newPiece = craftPiece(3,7);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;


        bm->pixel[3][7] = BLUE;
    
        newPiece = craftPiece(5,7);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[5][7] = BLUE;

        newPiece = craftPiece(7,7);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;


        bm->pixel[7][7] = BLUE;

        newPiece = craftPiece(0,6);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;


        bm->pixel[0][6] = BLUE;

        newPiece = craftPiece(2,6);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[2][6] = BLUE;

        newPiece = craftPiece(4,6);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[4][6] = BLUE;

        newPiece = craftPiece(6,6);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[6][6] = BLUE;

        newPiece = craftPiece(1,5);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;


        bm->pixel[1][5] = BLUE;
    
        newPiece = craftPiece(3,5);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[3][5] = BLUE;

        newPiece = craftPiece(5,5);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[5][5] = BLUE;
    
        newPiece = craftPiece(7,5);
        newPiece->next = COMPUTERHEAD;
        COMPUTERHEAD = newPiece;

        bm->pixel[7][5] = BLUE;

        showTeam(COMPUTERHEAD);
    }

}



