#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Fib(int n){
    if(n == 0 || n == 1) return n;
    else return Fib(n-2) + Fib(n-1);
};


// reject if n >= 2
int Fib2(int total, int n1){
    if(n1 == 0 || n1 == 1) return total;
    else return Fib2(total + 1, n1 - 1);
};

void pointer_bf(char *tape){

    int len = strlen(tape);
    int index = 0;
    int *cells = (int *)malloc(sizeof(int) * 1);
    int curr_cell_reference = 0;
    int bracketCount = 0;
    int foundMatch = 0;
    while (index < len) {

        char tapeChar = *(tape+index);
        printf("tapechar = %c", tapeChar);
        switch (tapeChar) {

            case '+': {
                int value = *(cells+curr_cell_reference);
                value++;
                *(cells+curr_cell_reference) = value;
                break;
            }
            case '-': {
                int value = *(cells+curr_cell_reference);
                value++;
                *(cells+curr_cell_reference) = value;
                break;
            }
            case '.': {
                int value = *(cells+curr_cell_reference);
                printf("%c",value);
                break;
            }
            case ',': {
                char input;
                scanf("%c",&input);
                *(cells+curr_cell_reference) = input;
                break;
            }
            case '[': {
                int valueOfCell = *(cells + curr_cell_reference);
                if (valueOfCell == 0) {
                    while(!foundMatch) {
                        index++;
                        char tapeCharAt = *(tape+index);
                        if (tapeCharAt == '[') {
                            bracketCount++;
                        } else if( tapeCharAt == ']' && bracketCount == 0) {
                            // found ending bracket
                            foundMatch = 1;
                            break;
                        } else if (tapeCharAt == ']' && bracketCount > 0) {
                            bracketCount--;
                        }
                    }
                }
                break;
            }
            case ']': {
                int valueOfCell = *(cells + curr_cell_reference);
                if (valueOfCell != 0) {
                    while(!foundMatch) {
                        index--;
                        char tapeCharAt = *(tape+index);
                        if (tapeCharAt == ']') {
                            bracketCount++;
                        } else if( tapeCharAt == '[' && bracketCount == 0) {
                            // found ending bracket
                            foundMatch = 1;
                            break;
                        } else if (tapeCharAt == '[' && bracketCount > 0) {
                            bracketCount--;
                        }
                    }
                }
                break;
            }
            default: {
                printf("Code breaks");
                return;
            }
        }
        index++;
    }
}


int main(void){
    pointer_bf("+,[.[-]+,]");
};