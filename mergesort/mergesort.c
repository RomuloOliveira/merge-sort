#include <stdlib.h>
#include "mergesort.h"

void merge(int* list, int begin, int middle, int end) {
    /*
    * Merge an array [begin..end] splitting in two sides A and B
    * A = [begin..middle-1]
    * B = [middle..end]
    */

    int len = end - begin + 1;
    int i = 0;
    int j = 0;
    int a = begin;
    int b = middle;

    int *temp = (int*) malloc(len * sizeof(int));

    /*
    * Iterates over array and select which one of side A or B should be selected
    */
    for (i = 0; i < len; i++) {
        if (a >= middle) { /* A side exhausted */
            temp[i] = list[b];
            b = b + 1;
        } else if (b > end) { /* B side exhausted */
            temp[i] = list[a];
            a = a + 1;
        } else if (list[a] < list[b]) {
            temp[i] = list[a];
            a = a + 1;
        } else {
            temp[i] = list[b];
            b = b + 1;
        }
    }

    /* Copy temp array to original */

    for (i = begin, j = 0; i <= end; i++, j++) {
        list[i] = temp[j];
    }

    free(temp);
}

void merge_sort(int* list, int begin, int end) {
    int middle = (begin + end + 1) / 2;

    if ((end - begin) < 1) {
        return;
    }

    merge_sort(list, begin, middle - 1);
    merge_sort(list, middle, end);

    merge(list, begin, middle, end);
}
