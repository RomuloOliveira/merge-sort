#include "mergesort.h"

void merge(int* list, int first_begin, int first_end, int second_begin, int second_end) {
    int i = 0;
    int j = 0;
    int swap = 0;
}

void merge_sort(int* list, int begin, int end) {
    int middle = (begin + end) / 2;

    if (begin - end < 1) {
        return;
    }

    merge_sort(list, begin, middle);
    merge_sort(list, middle, end);

    merge(list, begin, middle, middle, end);
}
