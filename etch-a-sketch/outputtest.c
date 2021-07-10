/*
 *
 * @author - Cameron Thacker
 *
 */


#include "project.h"

/*
 * Tests Framebuffer functionality, by asking the user to enter in two values, x and y coordinates, and then displaying the pre-determined color - White, on the sense hat
 * The Framebuffer test ends when the user does not enter any values, and the return of scanf is 0
 *
 * --------------------
 * --- Methods used ---
 * --------------------
 *
 * ##############
 * # FRAMEBUFFER
 * ##############
 *
 * openDisplay() - allocates Framebuffer object
 *
 * clearDisplay() - clears Framebuffer before Testing, to guarantee output shown is coordinates given
 *
 * displayColor(int,int,int) - Displays the color on to the sense hat, the location on the sense hat specified by the x and y coordinates given to the function
 *
 * closeDisplay() - deallocates the Framebuffer object
 *
 */


int main(){
    openDisplay();
    clearDisplay();
    int x,y,color=1;
    printf("\nEnter : x,y\n");
    while(scanf("%d,%d",&x,&y)){
        y=(y+8)%8;
        x=(x+8)%8;
        printf("\n%d,%d\n",x,y);
        displayColor(color,x,y);
        printf("\nEnter : x,y\n");
    }
    closeDisplay();

}
