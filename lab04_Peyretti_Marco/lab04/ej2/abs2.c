#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x < 0)
    {
        y = &x;
    *y = -x;
    }
    
    
}

int main(void) {
    int a=0, res=0;  
   

    absolute(a, &res);
    assert(res >= 0 && (res == a || res == -a));
    printf("%d\n", res);

    return EXIT_SUCCESS;
}

