#include <stdio.h>
#include <stdlib.h>

void soma(int *vet1, int *vet2, int *vet3, int n){

    for(int i = 0; i < n; i++){
        vet3[i] = vet1[i] + vet2[i];
    }
}

void inserir(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
    }
}

int main(){

    int tam;
    scanf("%d", &tam);

    int *vet1, *vet2, *vet_soma;

    vet1 = (int *)malloc(tam * sizeof(int));
    vet2 = (int *)malloc(tam * sizeof(int));
    vet_soma = (int *)malloc(tam * sizeof(int));

    if(vet1 == NULL || vet2 == NULL || vet_soma == NULL){
        return 1;
    }

    inserir(vet1, tam);
    inserir(vet2, tam);
    soma(vet1, vet2, vet_soma, tam);

    for(int i = 0; i < tam; i++){
        printf("%d\n", vet_soma[i]);
    }

    free(vet1);
    free(vet2);
    free(vet_soma);

    return 0;
}