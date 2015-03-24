#include <stdio.h>
#include "mergesort.h"

int main(int argc, char* argv[]) {
    int i = 0;
    int array[] = {9, 6, 7};

    printf("Hello, merge sort!\n");
    merge_sort(array, 0, 2);

    for (i = 0; i < 3; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
