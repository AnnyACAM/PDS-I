#include <stdio.h>
#include <string.h>

#define MAX 500


int main() {
    
    char string[MAX];
    
    scanf("%s", string);

    int tam = strlen(string);
    char novaString[MAX];
    
    int j = tam;
    novaString[0] = '\0';
    
    for(int i = 0; i < tam; i++){
        j--;
        novaString[j] = string[i];
    }
    
    printf("%s", novaString);
    
    return 0;
}
