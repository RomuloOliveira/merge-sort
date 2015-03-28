#include <stdio.h>

void usage(char* command) {
    printf("Usage: %s file.data int_0 int_1 int_2 ... int_n\n\n", command);
    printf("Create a binary file with sequential numbers int_0, int_1, int_2, ..., int_n\n\n");
    printf("Example: %s file.data 2 6 5\n", command);
}

int create_file(char* filename, char* argv[], int len) {
    FILE* f = fopen(filename, "wb");
    int i = 0;
    int n = 0;

    if (!f) {
        return -1;
    }

    for (i = 0; i < len; i++) {
        n = (int) strtol(argv[i], (char**) 0, 10);
        fwrite(&n, sizeof(n), 1, f);
    }

    fclose(f);

    return 0;
}

int main(int argc, char* argv[]) {
    int len = 0;
    char* filename = 0;

    if (argc < 3) {
        usage(argv[0]);
        return 1;
    }

    filename = argv[1];
    len = argc - 2;

    return create_file(filename, &argv[2], len);
}
