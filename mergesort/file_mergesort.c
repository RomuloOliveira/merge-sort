#include <stdio.h>

#include "file_mergesort.h"
#include "mergesort.h"
#include "../utils/utils.h"

void fmerge(FILE** file_list, size_t buffer_size, int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        fclose(file_list[i]);
    }
}

void fmerge_sort(FILE* f, size_t buffer_size, size_t max_size) {
    FILE **file_list = 0;

    int max_files = max_size / sizeof(FILE*);
    int len = buffer_size / sizeof(int);
    int len_read = 0;
    int times = 0;
    char filename[100]; // FIXME: change to #define MAX_SIZE 100

    int* buffer = (int*) malloc(buffer_size);

    file_list = (FILE**) malloc(max_size);

    while (1) {

        len_read = fread_file(f, buffer, len);

        if (!len_read) {
            break;
        }

        printf("len_read %d\n", len_read);
        merge_sort(buffer, 0, len_read - 1);

        snprintf(filename, 100, "temp %d", times);
        write_file(filename, buffer, len_read - 1);
        file_list[times] = fopen(filename, "rb");

        times = times + 1;
        print_array(buffer, len);
    };

    printf("Times %d\n", times);

    fmerge(file_list, buffer_size, times);

    free(buffer);
    free(file_list);
}
