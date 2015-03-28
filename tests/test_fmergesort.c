#include <assert.h>
#include <stdio.h>

#include "test_fmergesort.h"
#include "../utils/utils.h"
#include "../mergesort/file_mergesort.h"

void test_simple_fmerge_sort() {
    int a[] = {5, 6, 7, 1, 2, 5, 7, 9, 10, 0, 12, 6};
    FILE *f = 0;

    assert(write_file("file.temp", a, 12));

    f = fopen("file.temp", "rb");

    assert(f);

    fmerge_sort(f, sizeof(int) * 4, 12 * sizeof(int));

    fclose(f);
}
