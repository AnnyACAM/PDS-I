#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char string[MAX], opcao;

    strcpy(string, "167");
    int tam = strlen(string);
    int num = atoi(string);

    char result[MAX];
    int i = 0, aux;
    char letra;

    opcao = 'h';

    if (opcao == 'h') {
        do {
            if (num % 16 < 10) {
                result[i] = (num % 16) + '0';
            } else {
                letra = 'A';
                aux = (num % 16) - 10;
                result[i] = letra + aux;
            }
            num = num / 16;
            i++;
        } while (num > 0);
        
    } else if (opcao == 'o') {
        do {
            result[i] = (num % 8) + '0';
            num = num / 8;
            i++;
        } while (num > 0); 
        
    } else if (opcao == 'b') {
        do {
            result[i] = (num % 2) + '0';
            num = num / 2;
            i++;
        } while (num > 0); 
    }

    result[i] = '\0';
    char invertida[MAX];

    int k = i;

    for (int j = 0; j < i; j++) {
        k--;
        invertida[j] = result[k];
    }

    printf("-> %s\n", invertida);

    return 0;
}
