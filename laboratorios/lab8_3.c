#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTIDADE 8

typedef struct produto {
    char nome[50];
    char marca[50];
    float preco;
} Produto;

typedef struct marca {
    char nome[50];
    int quantidade;
    float soma_preco;
} Marca;

int main() {

    Produto produtos[QUANTIDADE];
    int qntd = 0;

    do {
        scanf("%s", produtos[qntd].nome);
        scanf("%s", produtos[qntd].marca);
        scanf("%f", &produtos[qntd].preco);
        qntd++;

    } while (qntd < QUANTIDADE);
    
    int qntd_marcas = 0, repetida;
    
    for (int i = 0; i < QUANTIDADE; i++) {
        repetida = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(produtos[i].marca, produtos[j].marca) == 0) {
                repetida = 1;
                break;
            }
        }
        if (!repetida) {
            qntd_marcas++;
        }
    }

    Marca *marcas = malloc(qntd_marcas * sizeof(Marca));
    
    for (int i = 0; i < QUANTIDADE; i++) {
        for (int j = 0; j < qntd_marcas; j++) {
            if (strcmp(marcas[j].nome, produtos[i].marca) == 0) {
                marcas[j].quantidade += 1;
                marcas[j].soma_preco += produtos[i].preco;
                break;
            }
            else if (marcas[j].quantidade == 0) {
                strcpy(marcas[j].nome, produtos[i].marca);
                marcas[j].quantidade = 1;
                marcas[j].soma_preco = produtos[i].preco;
                break;
            }
        }
    }
    for (int i = 0; i < qntd_marcas; i++) {
        printf("%s %d\n", marcas[i].nome, marcas[i].quantidade);
    }
    
    float total = 0;
    int quantidade_total = 0;

    for (int i = 0; i < qntd_marcas; i++) {
        total += marcas[i].soma_preco;
        quantidade_total += marcas[i].quantidade;
    }

    printf("media total %.2f\n", total / QUANTIDADE);

    for (int i = 0; i < qntd_marcas; i++) {
        printf("media %s %.2f\n", marcas[i].nome, marcas[i].soma_preco / marcas[i].quantidade);
    }
    
    free(marcas);

    return 0;
}
