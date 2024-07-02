#include <stdio.h>
#include <stdlib.h>

void media(double vet[], int n, int *i){
    
    double media = 0, menor = -1;
    double* aux = (double *)malloc(n * sizeof(double));

    if(aux == NULL){
        return 1;
    }

    for(int j = 0; j < n; j++){
        scanf("%lf", &vet[j]);
        media += vet[j];
    }

    media = media / n;    

    for(int j = 0; j < n; j++){
        aux[j] = media - vet[j];

        if(aux[j] < 0){
            aux[j] *= -1;
        }
        
        if(aux[j] < menor || menor < 0){
            menor = aux[j];
           *i = j;   
        }

    }

    free(aux);

}

int main(){
    int i, n;

    scanf("%d", &n);
    double* vet = (double *)malloc(n * sizeof(double));

    if(vet == NULL){
        return 1;
    }

    media(vet, n, &i);
    printf("%d", i);

    free(vet);
    return 0;
}