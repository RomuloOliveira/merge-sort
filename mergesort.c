#include <stdlib.h>
#include "mergesort.h"

void merge(int* list, int begin, int middle, int end) {
    int len = end - begin;
    int i = 0;
    int a = begin;
    int b = middle;

    int *temp = (int*) malloc(len * sizeof(int));

    for (i = begin; i <= end; i++) {
        if ((a < middle) && (b > end || list[a] < list[b])) {
            temp[i] = list[a];
            a = a + 1;
        } else {
            temp[i] = list[b];
            b = b + 1;
        }
    }

    for (i = begin; i <= end; i++) {
        list[i] = temp[i];
    }

    free(temp);
}

void merge_sort(int* list, int begin, int end) {
    int middle = (begin + end) / 2;

    if ((end - begin) <= 1) {
        return;
    }

    merge_sort(list, begin, middle);
    merge_sort(list, middle, end);

    merge(list, begin, middle, end);
}
