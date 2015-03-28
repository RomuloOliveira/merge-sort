#include <stdio.h>

void print_array(int* array, int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

/* Return 1 when array a is equal to array b, 0 otherwise */
int compare_array(int* a, int* b, int len);
