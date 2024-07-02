#include <stdio.h>
#include <stdlib.h>

void imprime (int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

void multiplica (int vetor[], int n, double v){
    for(int i = 0; i < n; i++){
        vetor[i] *= v;
    }
}

int main(){

    int tam;
    double mult;
    scanf("%d", &tam);

    int* vet = (int *)malloc(tam * sizeof(int));

    if(vet == NULL){
        return 1;
    }

    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    scanf("%lf", &mult);

    imprime(vet, tam);

    multiplica(vet, tam, mult);
    imprime(vet, tam);
    
    mult = 1/mult;
    multiplica(vet, tam, mult);
    imprime(vet, tam);

    free(vet);

    return 0;
}