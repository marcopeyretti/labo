#ifndef _FUNCIONES_EXTRAS_H_
#define _FUNCIONES_EXTRAS_H_

char *parse_filepath (int argc , char *argv[]);

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);

void sort(char sorted[] , unsigned int indexes[] , char letters[] , unsigned int length);

#endif