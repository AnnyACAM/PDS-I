#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

int leituraEntrada(char *string, int n){
    int num, j = 0;
    char aux[MAX];

    for(int i = 0;i < n; i++){
        if(string[i] >= '0' && string[i] <= '9'){
            aux[j] = string[i];
            j++;
        }
    }

    num = atoi(aux);

    return num;
}

int main(){
    
    int linhas, colunas;
    //scanf("%d %d", &linhas, &colunas); 

    char input[MAX];

    fgets(input, strlen(input), stdin);   
    linhas = leituraEntrada(input, MAX);

    fgets(input, strlen(input), stdin);   
    colunas = leituraEntrada(input, MAX);

    int **matriz = (int **)malloc(linhas * sizeof(int));
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));    
    }
   

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    

    return 0;
}