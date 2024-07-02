#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

void format(FILE *input, FILE *output) {
    char linha[MAX];

    //Pressione Enter para finalizar a leitura
    while (strcmp(fgets(linha, MAX, input),"\n") != 0) { 
        int i = 0;

        for (int j = 0; linha[j] != '\0'; j++) {
            linha[j] = tolower(linha[j]);
            
            if (!(linha[j] >= 'a' && linha[j] <= 'z')) {
                continue; 
            }

            linha[i] = linha[j];
            i++; 
        }

        linha[i++] = '\0';

        fprintf(output, "%s\n", linha);
    }
}

int main() {

    FILE *output = fopen("output.txt", "w"); 

    format(stdin, output);

    fclose(output);

    return 0;
}
