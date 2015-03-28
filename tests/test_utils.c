#include <assert.h>

#include "test_utils.h"
#include "../utils/utils.h"

void test_compare_array() {
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 5};

    assert(compare_array(a, a, 3));
    assert(compare_array(a, b, 2));
    assert(compare_array(a, b, 3) == 0);
}

void test_compare_empty_array() {
    int a[] = {};

    assert(compare_array(a, a, 0));
}

void test_write_read_file() {
    int a[] = {5, 6, 7};
    int b[] = {0, 0, 0};

    assert(write_file("file.temp", a, 3));
    assert(read_file("file.temp", b, 3));

    assert(compare_array(a, b, 3));
}
