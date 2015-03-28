#include <stdio.h>

#include "test_fmergesort.h"
#include "test_mergesort.h"
#include "test_utils.h"

void test(void (*fn)(), char* name) {
    printf("Testing %s\n", name);

    fn();
}

int main(int argc, char* argv[]) {
    test(test_simple, "test_simple");
    test(test_empty, "test_empty");
    test(test_reversed_list, "test_reversed_list");

    test(test_compare_array, "test_compare_array");
    test(test_compare_empty_array, "test_compare_empty_array");
    test(test_write_read_file, "test_write_read_file");

    test(test_simple_fmerge_sort, "test_simple_fmerge_sort");

    return 0;
}
