#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 800


void format_csv(FILE *input, FILE *output) {
   char linha[MAX];

    while (fgets(linha, sizeof(linha), input) != NULL) {

        char *token = strtok(linha, ";");

        while (token != NULL && token[0] != '\n') {
            fprintf(output, "%s\t", token); 
            token = strtok(NULL, ";");
        }

        fprintf(output, "\n");
    }
}

int main() {
    format_csv(stdin, stdout);

    return 0;
}
