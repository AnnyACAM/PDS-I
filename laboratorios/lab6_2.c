#include <stdio.h>
#define MAX 800

int main() {
    int fib[MAX], num, vetor[MAX], tam_vetor = 0;
    
    //Calcula as 800ª primeiras posições da sequência de fibonnaci
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= MAX; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    
    //Consulta Sequência
    scanf("%d", &num);

    while(!(num == -1 || num > 800)) {
        vetor[tam_vetor] = num;
        tam_vetor++;
        scanf("%d", &num);
    }
    
    for (int i = 0; i < tam_vetor; i++) {
        printf("%d \n", fib[vetor[i]]);
    }

    return 0;
}
