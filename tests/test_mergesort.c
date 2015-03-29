#include <assert.h>
#include <stdio.h>

#include "test_mergesort.h"
#include "../utils/utils.h"
#include "../mergesort/mergesort.h"

void test_simple() {
    int array[] = {
        9, 6, 7, 2, 5, 6,
        9, 6, 7, 2, 5, 6
    };

    merge_sort(array, 0, 11);

    assert(array[0] == 2);
    assert(array[1] == 2);
    assert(array[2] == 5);
    assert(array[3] == 5);
    assert(array[4] == 6);
    assert(array[5] == 6);
    assert(array[6] == 6);
    assert(array[7] == 6);
    assert(array[8] == 7);
    assert(array[9] == 7);
    assert(array[10] == 9);
    assert(array[11] == 9);
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
