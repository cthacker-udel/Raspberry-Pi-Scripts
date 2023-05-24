
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


pi_framebuffer_t * getDisplay(){
    return fb;
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


void displayNumberOfComputerPieces(){
    int count = 0;
    checkersPiece *head = COMPUTERHEAD;
    while(head != NULL){
        head = head->next;
        count++;
    }
    fprintf(stderr,"\n\n()()()()()() COMPUTER PIECES - %d ()()()()()()\n\n",count);
}

void displayNumberOfPlayerPieces(){
    int count = 0;
    checkersPiece *head = PLAYERHEAD;
    while(head != NULL){
        head = head->next;
        count++;
    }
    fprintf(stderr,"\n\n[][][][][][] PLAYER PIECES - %d [][][][][][]\n\n",count);
}

checkersPiece *getPlayerTeam(){
    return PLAYERHEAD;
}

checkersPiece *getComputerTeam(){
    return COMPUTERHEAD;
}

void currCursor(checkersPiece *currPiece){
    
    printf("\n\n---------------\nThe current turn(%d) is : %s",getTurn(),getTurn() == 1? "computer": "player");

    printf("\n\nCurrent coordinates of cursor are : %d,%d\n--------------------------\n",currPiece->xCoord,currPiece->yCoord);

    setDelay(750);
    int x = currPiece->xCoord;
    int y = currPiece->yCoord;
    sense_fb_bitmap_t *bm = fb->bitmap;
    while(1){
        checkJoystick();
        bm->pixel[x][y] = BLACK;
        break;
    }
}


void removePlayerPiece(int x, int y){

    checkersPiece *head = PLAYERHEAD;
    checkersPiece *prevPiece;

    fprintf(stderr,"\nRemove player piece passed the value : %d,%d",x,y);

    if(head->xCoord == x && head->yCoord == y){
        if(head->next == NULL){
            head = NULL;
            printf("\n\n~~~~~~ COMPUTER WON ~~~~~~\n\n");
            raise(SIGABRT);
            return;
        }
        else{
            displayNumberOfPlayerPieces();
            checkersPiece *tempHead = head->next;
            head->next = NULL;
            head = NULL;
            PLAYERHEAD = tempHead;
            displayNumberOfPlayerPieces();
            return;
        }
    }

    displayNumberOfPlayerPieces();
    while(head->next != NULL){
        prevPiece = head;
        head = head->next;
        if(head->xCoord == x && head->yCoord == y){
            prevPiece->next = head->next;
            head->next = NULL;
            head = NULL;
            displayNumberOfPlayerPieces();
            return;
        }
    }

}

void removeComputerPiece(int x, int y){
    
    checkersPiece *head = COMPUTERHEAD;
    checkersPiece *prevPiece;

    if(head->xCoord == x && head->yCoord == y){
        if(head->next == NULL){
            head = NULL;
            printf("\n\n~~~~~~~~~ PLAYER WON ~~~~~~~~~\n\n");
            raise(SIGABRT);
            return;
        }
        else{
            displayNumberOfComputerPieces();
            checkersPiece *tempHead = head->next;
            head->next = NULL;
            head = NULL;
            COMPUTERHEAD = tempHead;
            displayNumberOfComputerPieces();
            return;
        }
    }

    while(head->next != NULL){
        prevPiece = head;
        head = head->next;
        if(head->xCoord == x && head->yCoord == y){
            prevPiece->next = head->next;
            head->next = NULL;
            head = NULL;
            return;
        }
    }

}

void displayChooseMove(int x, int y, char color){
    sense_fb_bitmap_t *bm = fb->bitmap;
    switch(color){
        case 'g':
            bm->pixel[x][y] = GREEN;
            break;
        case 'b':
            bm->pixel[x][y] = BLUE;
            break;
        case 'r':
            bm->pixel[x][y] = RED;
            break;
        case 'o':
            bm->pixel[x][y] = ORANGE;
            break;
        case 'z':
            bm->pixel[x][y] = BLACK;
            break;
        default:
            break;
    }
}

int getColorVal(int x, int y){
    sense_fb_bitmap_t *bm = fb->bitmap;
    int colorVal = bm->pixel[x][y];
    return colorVal;
}


void display_created_user_team(){

    sense_fb_bitmap_t *bm = fb->bitmap;

    checkersPiece *head = PLAYERHEAD;

    while(head != NULL){
        bm->pixel[head->xCoord][head->yCoord] = RED;
        head = head->next;
    }

}


void display_created_computer_team(){
    
    sense_fb_bitmap_t *bm = fb->bitmap;

    checkersPiece *head = COMPUTERHEAD;

    while(head != NULL){
        bm->pixel[head->xCoord][head->yCoord] = BLUE;
        head = head->next;
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



