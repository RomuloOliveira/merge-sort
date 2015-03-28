#include <stdio.h>
#include "mergesort/mergesort.h"

int main(int argc, char* argv[]) {
    int i = 0;
    int array[] = {9, 6, 7, 2, 5, 6};

    printf("Hello, merge sort!\n");
    merge_sort(array, 0, 5);

    for (i = 0; i < 6; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
