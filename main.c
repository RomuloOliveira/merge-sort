#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mergesort/mergesort.h"
#include "utils/utils.h"

void help(char* command) {
    printf("Usage: %s int_0 int_1 int_2 ... int_n\n\n", command);
    printf("Sort an array composed by [int_0, int_1, int_2, ..., int_n]\n\n");
    printf("Example: %s 2 6 5\n", command);
    printf("Outputs: 2 5 6\n");
}

void copy_argv_to_array(int* array, char* argv[], int len) {
    int i = 0;

    for (i = 1 /* skip argv[0] */; i <= len; i++) {
        array[i - 1] = (int) strtol(argv[i], (char**) 0, 10);
    }
}

int main(int argc, char* argv[]) {
    int len = 0;
    int* array = 0;

    if (argc < 2) {
        help(argv[0]);
        return 1;
    }

    len = argc - 1;

    array = (int*) malloc(len * sizeof(int));

    copy_argv_to_array(array, argv, len);
    merge_sort(array, 0, len - 1);
    print_array(array, len);

    free(array);

    return 0;
}
