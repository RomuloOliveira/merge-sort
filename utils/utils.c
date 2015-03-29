#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

/* Return 1 when array a is equal to array b, 0 otherwise */
int compare_array(int* a, int* b, int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

int fread_file(FILE *f, int* array, int len) {
    int i = 0;
    int n = 0;
    int successful_read = 0;
    int read_count = 0;

    while (i < len) {
        if (feof(f)) {
            break;
        }

        successful_read = (int) fread(&n, sizeof(n), 1, f);

        if (!successful_read) {
            break;
        }

        read_count = read_count + successful_read;

        array[i] = n;
        i = i + 1;
    }

    return read_count;
}

int read_file(char* filename, int* array, int len) {
    FILE* f = fopen(filename, "rb");
    int ret = 0;

    if (!f) {
        return 0;
    }

    ret = fread_file(f, array, len);

    fclose(f);

    return ret;
}

int fwrite_file(FILE* f, int* array, int len) {
    int i = 0;
    int n = 0;

    for (i = 0; i < len; i++) {
        n = array[i];
        fwrite(&n, sizeof(n), 1, f);
    }

    return 1;
}

int write_file(char* filename, int* array, int len) {
    FILE* f = fopen(filename, "wb");
    int ret = 0;

    if (!f) {
        return 0;
    }

    ret = fwrite_file(f, array, len);

    fclose(f);

    return ret;
}

void copy_argv_to_array(int* array, char* argv[], int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        array[i] = (int) strtol(argv[i], (char**) 0, 10);
    }
}
