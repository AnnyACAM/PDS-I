#include <stdio.h>
#include <stdlib.h>

void inserir(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
    }
}

void imprimir(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d\n",vetor[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int* vetor = (int *)malloc(n * sizeof(int));

    if(vetor == NULL){
        return 1;
    }
    
    inserir(vetor, n);
    imprimir(vetor, n);

    free(vetor);

    return 0;
}