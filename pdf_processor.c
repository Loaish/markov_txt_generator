//processes PDF for Markov generator
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Function prototypes
void processFile(const char *filename);
void processLine(char *line, size_t len, FILE *outFile);

int main() {
    processFile("input.txt");
    return 0;
}


// tokenises a the text input - n-gram = 3
void processLine(char *line, size_t len, FILE *outFile) {
    int line_len = strlen(line);
    for (int i = 0; i <= line_len - 3; i++) {
        char ngram[4];
        strncpy(ngram, &line[i], 3);
        ngram[3] = '\0';
        printf("%s\n", ngram);
        fprintf(outFile, "%s\n", ngram);
    }
}

//accesses file and reads txt
void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    FILE *outFile = fopen("tokens.txt", "w");
    if (!file || !outFile) {
        printf("Error opening file.\n");
        return;
    }

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        processLine(line, len, outFile);
    }

    free(line);
    fclose(file);
    fclose(outFile);

}