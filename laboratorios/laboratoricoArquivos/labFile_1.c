#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300
#define MAX_LINE 800

int main() {
    char file_input[MAX], file_output[MAX];
    
    printf("Arquivo de entrada: ");
    scanf("%s", file_input);
    printf("Arquivo de saida: ");
    scanf("%s", file_output);

    FILE *input = fopen(file_input, "r"); 
    FILE *output = fopen(file_output, "w"); 

    if (input == NULL || output == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE];
    int qntd_conteudos = 0;

    while (fgets(line, sizeof(line), input)) {
        char *token, conteudo[MAX];
        int i = 0;

        if(qntd_conteudos > 0){
            token = strtok(line, ";");

            while (token != NULL && i < qntd_conteudos) {
                strcpy(conteudo, token);
                
                if(strcmp(conteudo,"\n") != 0){
                    
                    if(i < qntd_conteudos - 2){
                        fprintf(output, "%s\t|", conteudo);

                    }else{
                        fprintf(output, "%s\n", conteudo);
                    }

                    i++;
                }

                token = strtok(NULL, ";");
            }
        }else{
            qntd_conteudos = atoi(&line[0]);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
