
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100000

void print_help(char *program_name) {
 
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) 
{   
    char *result = NULL;

    bool valid_args_count = (argc == 2);

        if (!valid_args_count) 
        {
            print_help(argv[0]);
            exit(EXIT_FAILURE);
        }

    result = argv[1];

    return result;
}

unsigned int array_from_stdin(int array[],
                            unsigned int max_size) 
{
    FILE*input = stdin;
    unsigned int n;

    fscanf(input, "%u", &n);
    assert(n <= max_size);

    
        for (size_t i = 0; i < n; i++)
        {
            fscanf(input, "%d", &array[i]);
        }
    
    fclose(input);

    return n;
}

void array_dump(int a[], unsigned int length) 
{
    printf("\n[");
        for (size_t i=0;i<length-1;i++)
        {  
            printf(" %d,", a[i]);
        }
    printf(" %d]\n", a[length-1]);
}


int main(void) 
{
   int array[MAX_SIZE];
    
 
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    

    array_dump(array, length);
    
    return EXIT_SUCCESS;
}

