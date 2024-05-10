#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int x,y;
    x = 6;
    y = 4;
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return EXIT_SUCCESS;
}