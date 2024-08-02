#include <stdio.h>

#define PROGRAM_NAME "rot13"

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: No such file or directory\n", PROGRAM_NAME, argv[1]);
            return 1;
        }
    } else {
        fp = stdin;
    }

    #ifndef _WIN32
    setvbuf(stdout, NULL, _IOFBF, 0);
    #endif

    int c;
    while ((c = getc(fp)) != EOF) {
        if (c >= 65 && c <= 90) {
            putchar((c - 65 + 13) % 26 + 65);
        } else if (c >= 97 && c <= 122) {
            putchar((c - 97 + 13) % 26 + 97);
        } else {
            putchar(c);
        }
    }

    if (fp != stdin) {
        fclose(fp);
    }
    return 0;
}
