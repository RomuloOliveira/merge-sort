#include <stdio.h>

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

int read_file(char* filename, int* array, int len) {
    FILE* f = fopen(filename, "rb");
    int i = 0;
    int n = 0;
    int successful_read = 0;

    if (!f) {
        return 0;
    }

    while (1) {
        successful_read = (int) fread(&n, sizeof(n), 1, f);

        if (!successful_read) {
            break;
        }

        array[i] = n;
        i = i + 1;
    }

    fclose(f);

    return 1;
}

int write_file(char* filename, int* array, int len) {
    FILE* f = fopen(filename, "wb");
    int i = 0;
    int n = 0;

    if (!f) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        n = array[i];
        fwrite(&n, sizeof(n), 1, f);
    }

    fclose(f);

    return 1;
}

void copy_argv_to_array(int* array, char* argv[], int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        array[i] = (int) strtol(argv[i], (char**) 0, 10);
    }
}
