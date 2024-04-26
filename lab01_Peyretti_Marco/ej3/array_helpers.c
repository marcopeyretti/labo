#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



unsigned int array_from_file(int array[],
                            unsigned int max_size,
                            const char *filepath) 
{
  FILE *input = fopen(filepath,"r");
  unsigned int n;
    fscanf(input, " %u " , &n);
    assert (n<=max_size);
         for(size_t i=0;i<n;i++)
         {
            fscanf(input, " %d ", &array[i]);
         }
    fclose(input);
    return n;    
}

void array_dump(int a[], unsigned int length) 
{
    printf("\n[");
        for (size_t i=0;i<length;i++)
        {
            printf(" %d", a[i]);
        }
    printf("]\n");
}

