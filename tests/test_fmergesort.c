#include <assert.h>
#include <stdio.h>

#include "test_fmergesort.h"
#include "../utils/utils.h"
#include "../mergesort/file_mergesort.h"
#include "../mergesort/mergesort.h"

void test_simple_fmerge_sort() {
    int a[] = {
        16, 15, 14, 13,
        12, 11, 10, 9,
        8, 7, 6, 5,
        4, 3, 2, 1
    };

    int b[16];

    FILE *f = 0;
    merge_sort(a, 0, 5);

    assert(write_file("file.temp", a, 16));

    f = fopen("file.temp", "rb");
    assert(f);
    fmerge_sort(f, sizeof(int) * 2, 16 * sizeof(int));
    fclose(f);

    assert(read_file("file.temp", b, 16));
    merge_sort(a, 0, 15);

    assert(compare_array(a, b, 16));
}
