#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>

void print_array(int* array, int len);

/* Return 1 when array a is equal to array b, 0 otherwise */
int compare_array(int* a, int* b, int len);

/*
* Read a binary file composed by a sequence of integers.
* Return 1 if successful, 0 otherwise.
*/
int read_file(char* filename, int* array, int len);
int fread_file(FILE *f, int* array, int len);

/*
* Write a binary file composed by a sequence of integers.
* Return 1 if successful, 0 otherwise.
*/
int write_file(char* filename, int* array, int len);

void copy_argv_to_array(int* array, char* argv[], int len);

#endif
