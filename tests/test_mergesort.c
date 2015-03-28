#include <assert.h>
#include <stdio.h>

#include "test_mergesort.h"
#include "../utils/utils.h"

void test_simple() {
    int array[] = {9, 6, 7, 2, 5, 6};

    merge_sort(array, 0, 5);

    assert(array[0] == 2);
    assert(array[1] == 5);
    assert(array[2] == 6);
    assert(array[3] == 6);
    assert(array[4] == 7);
    assert(array[5] == 9);
}

void test_empty() {
    int array[] = {};

    merge_sort(array, 0, 0);
}

void test_reversed_list() {
    int array[] = {3, 2, 1};

    merge_sort(array, 0, 2);

    assert(array[0] == 1);
    assert(array[1] == 2);
    assert(array[2] == 3);
}
