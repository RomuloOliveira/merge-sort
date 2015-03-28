#include <stdio.h>
#include "test_mergesort.h"

void test(void (*fn)(), char* name) {
    printf("Testing %s\n", name);

    fn();
}

int main(int argc, char* argv[]) {
    test(test_simple, "test_simple");
    test(test_empty, "test_empty");
    test(test_reversed_list, "test_reversed_list");

    return 0;
}
