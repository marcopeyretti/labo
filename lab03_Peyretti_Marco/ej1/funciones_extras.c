#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "funciones_extras.h"


char *parse_filepath (int argc , char *argv[]) {

    char *result = NULL;

    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {        
        exit(EXIT_FAILURE);
    }

    result = argv[1];
    return result;
}


unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {

    unsigned int i = 0u; 

    FILE *archivo = NULL;

    archivo = fopen(path , "r");
    
    if (archivo == NULL) {

        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);

    }
    

    while (!feof(archivo)) {


        fscanf(archivo, "%u -> *%c*\n" , &indexes[i] , &letters[i]);



        if (indexes[i] > max_size) {

            fprintf(stderr, "Allowed size is %d.\n", max_size);
            exit(EXIT_FAILURE);

        }
        
        i++;
    }    

    fclose(archivo);

    return i;
}


void sort(char sorted[] , unsigned int indexes[] , char letters[] , unsigned int length){

    unsigned int *direc_indice = NULL;
    char *direc_sorted = NULL;

    for (size_t i = 0; i < length; i++) {

        direc_indice = &indexes[i];

        direc_sorted = &sorted[*direc_indice];

        *direc_sorted = letters[i];
        
    }
}



