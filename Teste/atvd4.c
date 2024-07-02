/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    int idade;
    float salario;
    int n_filhos;
} Dados;


int mediaSalario(Dados dados[], int n){
    int soma, media;
    
    for(int i = 0; i < n; i++){
        soma+= dados[i].salario;
    }
    
    media = soma/n;
    
    return media;
}

int mediaFilhos(Dados dados[], int n){
    int soma = 0, media = 0;
    
    for(int i = 0; i < n; i++){
        soma+= dados[i].n_filhos;
    }
    
    media = soma/n;
    
    return media;
}

int maiorSalario(Dados dados[], int n){
    int maior;
    
    for(int i = 0; i < n; i++){
        if(maior < dados[i].salario){
            maior = dados[i].salario;
        }
    }

    return maior;
}

int percentualSalario(Dados dados[], int n){
    int quantd = 0, percentual;
    
    for(int i = 0; i < n; i++){
        if(dados[i].salario > 1000){
            quantd++;
        }
    }
    
    percentual = quantd*100 / n;

    return percentual;
}
int main()
{
    Dados dados[10];
    int tamanho = 5;
    
    for(int i=0; i < 10; i++){
        dados[i].idade = rand() % (100 - 18 + 1) + 18;
        dados[i].salario = rand() % (8000 - 800 + 1) + 800;
        dados[i].n_filhos = rand() % (6 - 1 + 1) + 0;
    }
    
    printf("Média Salarial: %d\n", mediaSalario(dados, tamanho));
    printf("Média de Filhos: %d\n", mediaFilhos(dados, tamanho));
    printf("Maior Salario: %d\n", maiorSalario(dados, tamanho));
    printf("Percentual salario maior que $1000: %d\%\n", percentualSalario(dados, tamanho));
    
    return 0;
    
}
