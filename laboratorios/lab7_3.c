#include <stdio.h>
#include <string.h>

#define MAX 500


int main() {
    
    char string[MAX], C1, C2;
    
    scanf("%s", string);
    scanf(" %c %c", &C1, &C2);

    char *caracter = strchr(string, C1);
    
    if (caracter != NULL){
        int posicao = caracter - string;
        
        string[posicao] = C2;
        
        printf("%s", string);
    }

    
    return 0;
}
