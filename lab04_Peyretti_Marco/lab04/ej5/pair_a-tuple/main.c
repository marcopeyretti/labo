#include <stdlib.h>  
#include <stdio.h>   
#include "pair.h"    

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p.fst, p.snd);
}


int main(void) {
    pair_t p, q;
    p = pair_new(3, 4);
    printf("p = ");
    show_pair(p);
    q = pair_swapped(p);
    printf("q = ");
    show_pair(q);
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}
