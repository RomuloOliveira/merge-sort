#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mergesort/mergesort.h"
#include "utils/utils.h"

void usage(char* command) {
    printf("Usage: %s int_0 int_1 int_2 ... int_n\n\n", command);
    printf("Sort an array composed by [int_0, int_1, int_2, ..., int_n]\n\n");
    printf("Example: %s 2 6 5\n", command);
    printf("Outputs: 2 5 6\n");
}

int main(int argc, char* argv[]) {
    int len = 0;
    int* array = 0;

    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    len = argc - 1;

    array = (int*) malloc(len * sizeof(int));

    copy_argv_to_array(array, &argv[1], len);
    merge_sort(array, 0, len - 1);
    print_array(array, len);

    free(array);

    return 0;
}
