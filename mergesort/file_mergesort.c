#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "file_mergesort.h"
#include "mergesort.h"
#include "../utils/utils.h"

void copy_content(FILE* src, FILE* dst) {
    int a = 0;
    int read_a = 0;

    while (1) {
        read_a = (int) fread(&a, sizeof(a), 1, src);

        if (!read_a) {
            break;
        }

        fwrite(&a, sizeof(a), 1, dst);
    }
}

void fmerge(FILE* f, FILE** file_list, size_t buffer_size, int begin, int end) {
    int len = end - begin;
    FILE* f1 = 0;
    FILE* f2 = 0;
    FILE* f3 = 0;
    int a = 0;
    int read_a = 0;
    int b = 0;
    int read_b = 0;

    if (len < 1) {
        return;
    }

    if (len == 1) {
        f = freopen(0, "wb", f);
        copy_content(file_list[begin], f);
        fclose(file_list[begin]);
        return;
    }

    /* Sort two files */
    f1 = file_list[begin];
    f2 = file_list[begin + 1];
    f3 = tmpfile();

    read_a = (int) fread(&a, sizeof(a), 1, f1);
    read_b = (int) fread(&b, sizeof(b), 1, f2);
    while (1) {
        if (read_a && !read_b) {
            fwrite(&a, sizeof(a), 1, f3);
            read_a = (int) fread(&a, sizeof(a), 1, f1);
        } else if (read_b && !read_a) {
            fwrite(&b, sizeof(b), 1, f3);
            read_b = (int) fread(&b, sizeof(b), 1, f2);
        } else if (read_a && read_b) {
            if (a < b) {
                fwrite(&a, sizeof(a), 1, f3);
                read_a = (int) fread(&a, sizeof(a), 1, f1);
            } else {
                fwrite(&b, sizeof(b), 1, f3);
                read_b = (int) fread(&b, sizeof(b), 1, f2);
            }
        } else {
            break;
        }
    }

    fclose(f1);
    fclose(f2);

    f2 = tmpfile();

    rewind(f3);
    copy_content(f3, f2);
    fclose(f3);

    rewind(f2);
    file_list[begin + 1] = f2;

    fmerge(f, file_list, buffer_size, begin + 1, end);
}

void fmerge_sort(FILE* f, size_t buffer_size, size_t max_size) {
    FILE **file_list = 0;

    int len = buffer_size / sizeof(int);
    int len_read = 0;
    int times = 0;

    int* buffer = (int*) malloc(buffer_size);

    file_list = (FILE**) malloc(max_size);

    while (1) {

        len_read = fread_file(f, buffer, len);

        if (!len_read) {
            break;
        }

        merge_sort(buffer, 0, len_read - 1);

        file_list[times] = tmpfile();
        fwrite_file(file_list[times], buffer, len_read);
        rewind(file_list[times]);

        times = times + 1;
    };

    free(buffer);

    rewind(f);
    fmerge(f, file_list, buffer_size, 0, times);

    free(file_list);
}
