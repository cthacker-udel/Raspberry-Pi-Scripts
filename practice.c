#include <stdio.h>


int Fib(int n){
    if(n == 0 || n == 1) return n;
    else return Fib(n-2) + Fib(n-1);
};


// reject if n >= 2
int Fib2(int total, int n1){
    if(n1 == 0 || n1 == 1) return total;
    else return Fib2(total + 1, n1 - 1);
};

int main(void){
    printf("%d\n",Fib(5));
    printf("%d\n",Fib2(0,5));
};