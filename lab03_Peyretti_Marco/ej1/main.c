
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "funciones_extras.h"

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {

    printf("\"");

    for (unsigned int j=0u; j < length; j++) {

        printf("%c", a[j]);

    }

    printf("\"");
    printf("\n\n");
}


int main(int argc, char *argv[]) {

    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0u; 

    length = data_from_file(filepath , indexes , letters , MAX_SIZE);

    sort(sorted , indexes , letters , length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

