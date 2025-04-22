#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countFileStats(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            if (inWord) {
                inWord = 0;
                words++;
            }
        } else {
            inWord = 1;
        }
    }

    // If the last character was not a newline, count the last word
    if (inWord) {
        words++;
    }

    fclose(file);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    countFileStats(argv[1]);
    return 0;
}
